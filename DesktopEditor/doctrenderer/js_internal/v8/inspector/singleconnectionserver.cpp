#include "singleconnectionserver.h"
#include <iostream>//reporting errors

namespace ip = boost::asio::ip;
namespace beast = boost::beast;

//tmp
static std::size_t count = 0;

std::string NSJSBase::v8_debug::internal::SingleConnectionServer::getData()
{
    //check stream
    if (!checkStream()) {
        return std::string();
    }

    //set up buffer
    beast::multi_buffer buffer;
    //to check for err
    beast::error_code errCode;
    //read into buffer; blocks here
    m_pWebsocketStream->read(buffer, errCode);
    //check for error
    if (errCode) {
        if (//cdt disconnection
                errCode == boost::asio::error::operation_aborted
                ) {
            setDisconnected();
            return std::string();
        }
        reportError(errCode, "while reading");
        return std::string();
    }
    //set mode equal to incoming message mode
    m_pWebsocketStream->text(
                //returns true if socket got text message, false on binary
                m_pWebsocketStream->got_text()
                );
    //return value read
    return boost::beast::buffers_to_string(buffer.data());
}

beast::error_code NSJSBase::v8_debug::internal::SingleConnectionServer::discardData()
{
    //check stream
    if (!checkStream()) {
        return beast::error_code();
    }

    beast::flat_buffer buffer;//no need in multi buffer
    beast::error_code errCode;
    m_pWebsocketStream->read(buffer, errCode);
    return errCode;
}

void NSJSBase::v8_debug::internal::SingleConnectionServer::reportError(
        const beast::error_code &code
        , const char *context) const
{
    std::cerr << context << ": error with code " << code << ": " << code.message() << std::endl;
}

void NSJSBase::v8_debug::internal::SingleConnectionServer::setConnected()
{
    m_bCdtConnected = true;
}

void NSJSBase::v8_debug::internal::SingleConnectionServer::setDisconnected()
{
    m_bCdtConnected = false;
}

bool NSJSBase::v8_debug::internal::SingleConnectionServer::checkStream()
{
    if (!m_pWebsocketStream) {
        std::cerr << "no websocket stream when requested one" << std::endl;
        setDisconnected();
        return false;
    }
    return true;
}

NSJSBase::v8_debug::internal::SingleConnectionServer::SingleConnectionServer(uint16_t port
                                                                             , std::string host)
    //set up endpoint
    : m_Endpoint(
          ip::make_address(host)
          , port
          )

    //constructs unopened acceptor
    , m_ConnectionAcceptor(
          m_io_context
          )

{
    //tmp
    count = 0;
}

void NSJSBase::v8_debug::internal::SingleConnectionServer::setOnMessageCallback(
        onMessageCallback callback)
{
    m_fOnMessage = std::move(callback);
}

bool NSJSBase::v8_debug::internal::SingleConnectionServer::waitForConnection()
{
    //to check errors
    boost::beast::error_code errCode;
    //make socket on io context
    tcp::socket socket{m_io_context};
    //blocks until connected
    m_ConnectionAcceptor.accept(socket, errCode);
    //check for error
    if (errCode) {
        reportError(errCode, "while accepting connection");
        return false;
    }
    //set up websocket stream
    m_pWebsocketStream = std::make_unique<stream_t>(
                //moving local object to stream
                std::move(socket)
                );
    //accept client handshake
    m_pWebsocketStream->accept(errCode);
    //check error
    if (errCode) {
        reportError(errCode, "while accepting client handshake");
        return false;
    }
    //connection established
    setConnected();
    return true;
}

bool NSJSBase::v8_debug::internal::SingleConnectionServer::listen()
{
    //
    boost::beast::error_code errCode;

    //open acceptor with endpoint's protocol
    m_ConnectionAcceptor.open(m_Endpoint.protocol(), errCode);
    //check for error
    if (errCode) {
        reportError(errCode, "while opening acceptor");
        return false;
    }

    //bind acceptor to endpoint
    m_ConnectionAcceptor.bind(m_Endpoint, errCode);
    //check for error
    if (errCode) {
        reportError(errCode, "while binding acceptor to endpoint");
        return false;
    }

    //listen
    m_ConnectionAcceptor.listen(
                1//max amount of pending connections
                , errCode);
    //check for error
    if (errCode) {
        reportError(errCode, "while attempting to listen");
        return false;
    }

    m_bListening = true;
    return true;
}

//blocks
void NSJSBase::v8_debug::internal::SingleConnectionServer::run()
{
    while (waitAndProcessMessage()) {
        std::clog << "SingleConnectionServer: waiting for message in loop " << count++ << std::endl;
    }
}

void NSJSBase::v8_debug::internal::SingleConnectionServer::sendData(const std::string &data)
{
    //check stream
    if (!checkStream()) {
        return;
    }

    //write data to buffer
    beast::multi_buffer buffer;
    beast::ostream(buffer) << data;

    //text or binary mode as already set
    boost::beast::error_code errCode;
    m_pWebsocketStream->write(buffer.data(), errCode);
    if (errCode) {
        reportError(errCode, "while sending data");
        return;
    }
}

bool NSJSBase::v8_debug::internal::SingleConnectionServer::waitAndProcessMessage()
{
    std::string data = getData();
    if (!connected()) {
        return false;
    }
    m_fOnMessage(data);
    return true;
}

bool NSJSBase::v8_debug::internal::SingleConnectionServer::connected() const
{
    return m_bCdtConnected;
}

bool NSJSBase::v8_debug::internal::SingleConnectionServer::listening() const
{
    return m_bListening;
}

bool NSJSBase::v8_debug::internal::SingleConnectionServer::shutdown()
{
    //check stream
    if (checkStream()) {
        return false;
    }

    beast::error_code errCode;
    //send close frame
    m_pWebsocketStream->close(beast::websocket::close_code::normal, errCode);
    if (errCode) {
        reportError(errCode, "while closing");
        return false;
    }

    //discard pending messages until receiving close frame
    while (true) {
        //read and get error_code
        errCode = discardData();

        //close frame is delivered as closed error
        if (errCode == beast::websocket::error::closed) {
            return true;
        }

        //any other errors
        if (errCode) {
            reportError(errCode, "while waiting for close responce at close");
            return false;
        }
    }
}

uint16_t NSJSBase::v8_debug::internal::SingleConnectionServer::port() const
{
    return m_Endpoint.port();
}
