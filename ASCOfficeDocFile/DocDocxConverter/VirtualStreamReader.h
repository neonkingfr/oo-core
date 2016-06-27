﻿/*
 * (c) Copyright Ascensio System SIA 2010-2016
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
#pragma once

#include "IBinaryReader.h"
#include "../Common/FormatUtils.h"
#include "../../Common/3dParty/pole/pole.h"
#include "../../Common/DocxFormat/Source/Base/Types_32.h"

class VirtualStreamReader : public IBinaryReader
{
public:
	VirtualStreamReader (POLE::Stream* _stream, ULONG _position , bool _olderVersion) : 
				olderVersion(_olderVersion), stream(_stream), position(_position)
	{
		if ( stream == NULL )return;

		stream->seek(position);
	}

	virtual ~VirtualStreamReader()
	{
	}

	virtual unsigned short ReadUInt16()
	{
		unsigned short rdUShort = 0;

		if (( stream != NULL ) && (position + 2 < stream->size()))
		{		
			stream->seek( position );
			stream->read((unsigned char*)(&rdUShort), sizeof( rdUShort ));
		}
		position += sizeof( rdUShort );

		return rdUShort;
	}

	virtual short ReadInt16()
	{
		short rdShort = 0;

		if (( stream != NULL ) && (position + 2 < stream->size()))
		{
			stream->seek( position );
			stream->read((unsigned char*)(&rdShort), sizeof( rdShort ));
			
		}
		position += sizeof( rdShort );

		return rdShort;
	}

	virtual int ReadInt32()
	{
		_INT32 rdInt = 0;

		if (( stream != NULL ) && (position + 4 < stream->size()))
		{
			stream->seek( position );
			stream->read( (unsigned char*) &rdInt, sizeof( rdInt ) );
			
		}
		position += sizeof( rdInt );

		return rdInt;
	}

	virtual unsigned int ReadUInt32()
	{
		_UINT32 rdUInt = 0;

		if (( stream != NULL ) && (position + 4 < stream->size()))
		{
			stream->seek( position );
			stream->read((unsigned char*) &rdUInt, sizeof( rdUInt ) );
		
		}
		position += sizeof( rdUInt );

		return rdUInt;
	}

	virtual unsigned char ReadByte()
	{
		unsigned char rdByte = 0;

		if (( stream != NULL ) && (position + 1 < stream->size()))
		{
			stream->seek( position);
			stream->read( (unsigned char*)&rdByte, sizeof( rdByte ) );
			
		}
		position += sizeof( rdByte );

		return rdByte;
	}

	virtual unsigned char* ReadBytes( unsigned int count, bool isResultNeeded )
	{
		unsigned char *rdBytes = NULL;

		if ( count > 0  && isResultNeeded)
		{
			if (position + count > stream->size())
			{
				if (position > stream->size())	count = 0;
				else							count = stream->size() - position;
			}
			rdBytes = new unsigned char[count];
		}

		if ( stream != NULL  && rdBytes != NULL )
		{
			stream->seek( position );
			stream->read( rdBytes, sizeof( unsigned char )*count );
		}
		
		position += sizeof( unsigned char )*count;

		return rdBytes;
	}

	virtual unsigned long GetPosition() const
	{
		return this->position;
	}

	virtual unsigned long GetSize() const
	{
		unsigned long size = 0;

		if ( stream != NULL )
		{
			size = stream->size();
		}

		return size;
	}

	virtual int Seek( int offset, int origin )
	{
		if ( stream != NULL )
		{
			if (origin > 1)
			{

			}
			stream->seek( offset );
			position = offset;
			return offset;
		}
		else
		{
			return 0;
		}
	}

	std::wstring ReadXst()
	{
		std::wstring wstrResult( _T( "" ) );
		if (stream)
		{
			int cchSize = 2;
			unsigned char* cch = this->ReadBytes( cchSize, true );

			int xstzSize = FormatUtils::BytesToInt16( cch, 0, cchSize ) * 2;      
			unsigned char* xstz = ReadBytes(xstzSize, true);

			if (this->olderVersion)
			{
				FormatUtils::GetSTLCollectionFromBytes<std::wstring>( &wstrResult, xstz, xstzSize, ENCODING_WINDOWS_1250 );
			}
			else
			{
				FormatUtils::GetSTLCollectionFromBytes<std::wstring>( &wstrResult, xstz, xstzSize, ENCODING_UTF16 );
			}

			RELEASEARRAYOBJECTS(xstz);
			RELEASEARRAYOBJECTS(cch);
		}

		return wstrResult;
	}

	/// Read a length prefixed Unicode string from the given stream.
	/// The string must have the following structure:
	/// unsigned char 1 - 4: Character count (cch)
	/// unsigned char 5 - (cch*2)+4: Unicode characters terminated by \0
	std::wstring ReadLengthPrefixedUnicodeString()
	{
		std::wstring result;

		int cch = ReadInt32();

		if ( cch > 0 )
		{
			//dont read the terminating zero
			unsigned char* stringBytes = ReadBytes( ( cch * 2 ), true );

			FormatUtils::GetSTLCollectionFromBytes<std::wstring>( &result, stringBytes, ( ( cch * 2 ) - 2 ), ENCODING_UTF16 );

			RELEASEARRAYOBJECTS( stringBytes );
		}

		return result;
	}

	/// Read a length prefixed ANSI string from the given stream.
	/// The string must have the following structure:
	/// unsigned char 1-4: Character count (cch)
	/// unsigned char 5-cch+4:   ANSI characters terminated by \0
	std::wstring ReadLengthPrefixedAnsiString()
	{
		std::wstring result;

		int cch = this->ReadInt32();

		if ( cch > 0 )
		{
			//dont read the terminating zero
			unsigned char* stringBytes = ReadBytes( cch, true );

			FormatUtils::GetSTLCollectionFromBytes<std::wstring>( &result, stringBytes, ( cch - 1 ), ENCODING_WINDOWS_1250);

			RELEASEARRAYOBJECTS( stringBytes );
		}

		return result;
	}
	bool			olderVersion;
private:

	POLE::uint64			position;
	POLE::Stream*			stream;
};
