#pragma once
#include "RtfPicture.h"
#include "../Common/MediaFormatDefine.h"

class RtfShape: public IRenderableProperty
{
public: typedef enum{ st_none, st_inline, st_anchor }ShapeType;
public: typedef enum{
			ax_none,
			//ax_ignore, //\shpbxignore	Ignore \shpbxpage, \shpbxmargin, and \shpbxcolumn, in favor of the posrelh property. The ignored properties will be written for backward compatibility with older readers that do not understand \posrelh.
			ax_page, //\shpbxpage 	The shape is positioned relative to the page in the x (horizontal) direction. 
			ax_margin, //\shpbxmargin 	The shape is positioned relative to the margin in the x (horizontal) direction.
			ax_column //\shpbxcolumn	The shape is positioned relative to the column in the x (horizontal) direction.
		}AnchorX;
public: typedef enum{ 
			ay_none,
			//ay_ignore, //\shpbyignore	Ignore \shpbypage, \shpbymargin, and \shpbxpara, in favor of the posrelh property. The ignored properties will be written for backward compatibility with older readers that do not understand the posrelh property.
			ay_page, //\shpbypage 	The shape is positioned relative to the page in the y (vertical) direction. 
			ay_margin, //\shpbymargin 	The shape is positioned relative to the margin in the y (vertical) direction.
			ay_Para //\shpbypara	The shape is positioned relative to the paragraph in the y (vertical) direction.
		}AnchorY;

public: ShapeType m_eShapeType;

public: int m_nLeft; //\shpleftN	Specifies position of shape from the left of the anchor. The value N is in twips.
public: int m_nTop; //\shptopN	Specifies position of shape from the top of the anchor. The value N is in twips.
public: int m_nBottom; //\shpbottomN	Specifies position of shape from the bottom of the anchor. The value N is in twips.
public: int m_nRight; //\shprightN	Specifies position of shape from the right of the anchor. The value N is in twips.
public: int m_nID; //\shplidN	A number that is unique to each shape. This keyword is primarily used for linked text boxes. The value N is a long integer.
public: int m_nZOrder; //\shpzN	Describes the z-order of the shape. It starts at 0 for the shape that is furthest from the top, and proceeds to the top most shape (N). The shapes that appear inside the header document will have a separate z-order, compared to the z-order of the shapes in the main document. For instance, both the back-most shape in the header and the back-most main-document shape will have a z-order of 0.
public: int m_nHeader; //\shpfhdrN	Set to 0 if the shape is in the main document. Set to 1 if the shape is in the header document.
public: int m_nWrapType; //\shpwrN	Describes the type of wrap for the shape:
public: int m_nWrapSideType; //\shpwrkN	Wrap on side (for types 2 and 4 for \shpwrN ):
public: int m_nZOrderRelative; //\shpfblwtxtN	Describes relative z-ordering:
public: int m_bLockAnchor; //\shplockanchor	Lock anchor for a shape.
public: AnchorX m_eXAnchor;
public: AnchorY m_eYAnchor;
//----------------ShapeProperty--------------------
//Position absolute
public: int m_nPositionH; //posh	Horizontal alignment
public: int m_nPositionHRelative; //posrelh	Position horizontally relative to:
public: int m_nPositionV; //posv	Vertical alignment:
public: int m_nPositionVRelative; //posrelv Position horizontally relative to:
public: int m_bLayoutInCell; //fLayoutInCell	Allows shape to anchor and position inside table cells.
public: int m_bAllowOverlap; //fAllowOverlap	Allows shape to overlap other shapes unless it is a shape with None wrapping (\shpwr3), in which case it can always overlap an object with other types of wrapping and vice-versa. 
//Position relative
public: int m_nPositionHPct; //pctHorizPos Percentage horizontal position for a shape
public: int m_nPositionVPct; //pctVert Percentage vertical position for a shape
public: int m_nPctWidth; //pctHoriz Percentage width for a shape
public: int m_nPctHeight; //pctVert Percentage height for a shape
public: int m_nPctWidthRelative; //sizerelh Relative size horizontal relation
public: int m_nPctHeightRelative; //sizerelv Relative size vertical relation
public: int m_nColStart; //colStart Starting column
public: int m_nColSpan; //colSpan Number of columns to span
//Rehydration
public: CString m_sMetroBlob; // metroBlob Specifies application-specific data used to convert a shape to other formats. It is an encoded TBYTE stream.
public: CString m_sMetroBlobRels;
public: CString m_sMetroBlobData;


//Object Type
public: int m_bIsBullet; //fIsBullet Indicates whether a picture was inserted as a picture bullet.
public: int m_nRotation; //rotation	Rotation of the shape.	Angle	0
public: int m_bFlipV; //fFlipV	Vertical flip, applied after the rotation.	Boolean	FALSE
public: int m_bFlipH; //fFlipH	Horizontal flip, applied after the rotation.	Boolean	FALSE
public: int m_nShapeType; //shapeType	See below for values. 0 indicates user-drawn freeforms and polygons. 	Not applicable	Not applicable
public: int m_nWrapDistLeft; //dxWrapDistLeft	Left wrapping distance from text.
public: int m_nWrapDistTop; //
public: int m_nWrapDistRight; //
public: int m_nWrapDistBottom; //
//public: int m_bBehindDocument; //fBehindDocument Place the shape behind text.	Boolean	FALSE
public: int m_bHidden; //fHidden	Do not display or print (only set through Visual Basic for Applications).	Boolean	FALSE

//Text box
public: int m_nTexpLeft; //dxTextLeft	Left internal margin of the text box. EMU	91,440
public: int m_nTexpTop; //
public: int m_nTexpRight; //
public: int m_nTexpBottom; //

//Geometry
public: int m_nAdjustValue; //adjustValue	First adjust value from an adjust handle. The interpretation varies with the shape type. Adjust values alter the geometry of the shape in smart ways. 	Integer	0
public: int m_nAdjustValue2;
public: int m_nAdjustValue3;
public: int m_nAdjustValue4;
public: int m_nAdjustValue5;
public: int m_nAdjustValue6;
public: int m_nAdjustValue7;
public: int m_nAdjustValue8;
public: int m_nAdjustValue9;
public: int m_nAdjustValue10;
//Connectors
public: int m_nConnectionType; //cxk Connection site type
public: int m_nConnectorStyle; //cxstyle Connector style

//WordArt Effects
public: int m_nCropFromTop; //cropFromTop	Top cropping percentage. ���������� � fraction 1 /65536
public: int m_nCropFromBottom; //cropFromBottom	Bottom cropping percentage.
public: int m_nCropFromLeft; //cropFromLeft	Left cropping percentage.
public: int m_nCropFromRight; //cropFromRight	Right cropping percentage.
//Grouped Shapes
public: int m_nGroupBottom; //groupBottom	Defines the height of the group rectangle, but does not necessarily indicate position on the page. The difference between groupBottom and groupTop should match the dimensions specified by \shptopN and \shpbottomN.
public: int m_nGroupLeft; //groupLeft	Defines the width of the group rectangle, but does not necessarily indicate position on the page. The difference between groupLeft and groupRight should match the dimensions specified by \shpleftN and \shprightN.
public: int m_nGroupRight; //groupRight	See meaning for groupLeft.
public: int m_nGroupTop; //groupTop	See meaning for groupBottom.
public: int m_nRelBottom; //relBottom	Defines the bottom of a shape within its parent shape (used for shapes in a group). The measurement is relative to the position of the parent group or drawing.
public: int m_nRelLeft; //relLeft	Defines the left of a shape within its parent shape (used for shapes in a group). The measurement is relative to the position of the parent group or drawing.
public: int m_nRelRight; //relRight	Defines the right of a shape within its parent shape (used for shapes in a group). The measurement is relative to the position of the parent group or drawing.
public: int m_nRelTop; //relTop	Defines the top of a shape within its parent shape (used for shapes in a group). The measurement is relative to the position of the parent group or drawing.
public: int m_nRelRotation; //relRotation	Represents the information stored in the site of a shape, which defines the size and location of the shape in the parent group or drawing. The coordinates are relative to the position of the parent group or drawing. The units are relative to the m_rcg of the parent.
public: int m_nRelZOrder;//dhgt	Word 2007 Z-order position of shape(s) on a page. Shapes with small dhgts are further back than shapes with large dhgts.

//Fill
public: int m_bFilled; //fFilled The shape is filled.
//Line
public: int m_bLine; //fLine Has a line
public: int m_nLineStartArrow; //lineStartArrowhead Start arrow type:
public: int m_nLineEndArrow; //lineEndArrowhead	End arrow type (for acceptable values see meaning for lineStartArrowhead).
public: int m_nLineStartArrowWidth; //lineStartArrowWidth	Start arrow width:
public: int m_nLineStartArrowLength; //lineStartArrowLength	Start arrow length:
public: int m_nLineEndArrowWidth; //lineEndArrowWidth	End arrow width (for acceptable values see meaning for lineStartArrowWidth).
public: int m_nLineEndArrowLength; //lineEndArrowLength	End arrow length (for acceptable values see meaning for lineStartArrowLength).

//pWrapPolygonVertices	Points of the text wrap polygon.
public: CAtlArray< int > m_aWrapPoints;
//textbox
public: TextItemContainerPtr m_aTextItems;
public: RtfPicturePtr m_oPicture;
public: bool m_bIsOle;

public: RtfShape()
		{
			SetDefault();
		}
//public: bool ParseMetroBlob(CString sTargetDirectory )
//		{
//			if( true == m_sMetroBlob.IsEmpty() )
//				return false;
//			if( false == m_sMetroBlobRels.IsEmpty() &&  false == m_sMetroBlobRels.IsEmpty() )
//				return true;
//			CString sTempDirectory = sTargetDirectory + _T("\\Temp");
//			CreateDirectory(sTempDirectory, NULL);
//			CString sArchiveFile = sTempDirectory + _T("\\Archive.zip");
//			CString sArchiveFolder = sTempDirectory + _T("\\Archive");
//			//���������� � �����
//			RtfUtility::WriteDataToFile( sArchiveFile, m_sMetroBlob );
//			
//			//������������� �����
//			ASCOfficeUtils::IOfficeUtils* piZipUtil = NULL;
//			HRESULT hRes = CoCreateInstance( ASCOfficeUtils::CLSID_COfficeUtils , NULL, CLSCTX_INPROC, ASCOfficeUtils::IID_IOfficeUtils, (void**)(&piZipUtil));
//			if( FAILED( hRes ) || NULL == piZipUtil )
//			 return false; 
//			BSTR bstrZipFile = sArchiveFile.AllocSysString();
//			BSTR bstrUnZipDirectory = sArchiveFolder.AllocSysString();
//			BSTR bstrPassword = NULL;
//			piZipUtil->ExtractToDirectory(bstrZipFile, bstrUnZipDirectory, bstrPassword, 0);
//			SysFreeString( bstrZipFile );
//			SysFreeString( bstrUnZipDirectory );
//			RELEASEINTERFACE( piZipUtil );
//
//			//�� rels ���� ��������
//			CString sDrawingDocPath;
//			XmlUtils::CXmlReader oXmlReader;
//			if( FALSE == oXmlReader.OpenFromFile( sArchiveFolder + _T("\\_rels\\.rels") ) )
//				return false;
//			oXmlReader.ReadRootNode( _T("Relationships") );
//			oXmlReader.ReadNodeList( _T("Relationship") );
//			for( int i = 0; i < oXmlReader.GetLengthList(); i++ )
//			{
//				CString sType = oXmlReader.ReadNodeAttribute( i,_T("Type"), _T("") );
//				CString sTarget = oXmlReader.ReadNodeAttribute( i,_T("Type"), _T("") );
//				if( sType == _T("http://shemas.microsoft.com/office/2006/relationships/graphicFrameDoc") && false == sTarget.IsEmpty() )
//					sDrawingDocPath = sArchiveFile + sTarget;
//			}
//			if( sDrawingDocPath.IsEmpty() )
//				return false;
//			//��������� m_sMetroBlobData
//			XmlUtils::CXmlReader oXmlDataReader;
//			oXmlDataReader.OpenFromFile( sDrawingDocPath );
//			oXmlDataReader.ReadRootNode(_T("wp:e2oholder"));
//			oXmlDataReader.ReadNodeList(_T("*"));
//			for( int i = 0; i < oXmlDataReader.GetLengthList(); i++ )
//				m_sMetroBlobData.Append( oXmlDataReader.ReadNodeXml( i ) );
//
//			//������ rels �������� �����
//			TCHAR strDir[256];
//			_tsplitpath( sDrawingDocPath, NULL, strDir, NULL, NULL );
//			CString sDocumentDirectory(strDir);
//			CString sDocRels = sDocumentDirectory + _T("\\_rels\\e2oDoc.xml.rels");
//
//			CAtlArray<CString> aDirectories;
//			XmlUtils::CXmlReader oXmlRelsReader;
//			oXmlReader.OpenFromFile( sDocRels );
//			oXmlReader.ReadRootNode(_T("Relationships"));
//			oXmlReader.ReadNodeList(_T("Relationship"));
//			for( int i = 0; i < oXmlReader.GetLengthList(); i++ )
//			{
//				CString sType = oXmlReader.ReadNodeAttribute( _T("Type"), _T("") );
//				CString sTarget = oXmlReader.ReadNodeAttribute( _T("Target"), _T("") );
//				CString sId = oXmlReader.ReadNodeAttribute( _T("Id"), _T("") );
//				CString sNewId = IdGenerator::Generate_rId();
//				
//				//������� ���� ��� ��� �����
//				int nSleshIndex = sTarget.Find('\\',0);
//				if( nSleshIndex != -1 )
//				{
//					CString sFileDirectory = sTarget.Left(nSleshIndex);
//					//��������� ���������� �� �� �� ���
//					bool bIsCopy = false;
//					for( int i = 0; i < (int)aDirectories.GetCount(); i++ )
//						if( aDirectories[i] == sFileDirectory )
//						{
//							bIsCopy = true;
//							break;
//						}
//					if( false == bIsCopy )
//						Utils::CopyDirOrFile( sDocumentDirectory + sFileDirectory, sTargetDirectory );
//				}
//				else
//					Utils::CopyDirOrFile( sDocumentDirectory + sTarget, sTargetDirectory );
//				m_sMetroBlobRels.Append( oXmlReader.ReadNodeXml( i ) );
//				m_sMetroBlobRels.Replace(sId, sNewId);
//				m_sMetroBlobData.Replace(sId, sNewId);
//			}
//			Utils::RemoveDirOrFile( sTempDirectory );
//			return true;
//		}

public: bool IsValid()
		{
			return PROP_DEF != m_nShapeType;
		}
public: void SetDefaultRtf()
		{
			SetDefault();
		}
public: void SetDefaultOOX()
		{
			SetDefault();
		}
public: void SetDefault()
		{
			m_eShapeType = st_none;

			//Common
			DEFAULT_PROPERTY( m_nLeft )
			DEFAULT_PROPERTY( m_nTop )
			DEFAULT_PROPERTY( m_nBottom )
			DEFAULT_PROPERTY( m_nRight )
			DEFAULT_PROPERTY( m_nID )
			DEFAULT_PROPERTY( m_nZOrder )
			DEFAULT_PROPERTY( m_nHeader )
			DEFAULT_PROPERTY( m_nWrapType )
			DEFAULT_PROPERTY( m_nWrapSideType )
			DEFAULT_PROPERTY( m_nZOrderRelative )
			DEFAULT_PROPERTY( m_bLockAnchor )
			DEFAULT_PROPERTY_DEF( m_eXAnchor, ax_column ) //�� ��������� - �������� � ������
			DEFAULT_PROPERTY_DEF( m_eYAnchor, ay_Para )//�� ��������� - �������� � ������

			//Position absolute
			DEFAULT_PROPERTY( m_nPositionH )
			DEFAULT_PROPERTY( m_nPositionHRelative )
			DEFAULT_PROPERTY( m_nPositionV )
			DEFAULT_PROPERTY( m_nPositionVRelative )
			DEFAULT_PROPERTY( m_bLayoutInCell )
			DEFAULT_PROPERTY( m_bAllowOverlap )

			//Position relative
			DEFAULT_PROPERTY( m_nPositionHPct )
			DEFAULT_PROPERTY( m_nPositionVPct )
			DEFAULT_PROPERTY( m_nPctWidth )
			DEFAULT_PROPERTY( m_nPctHeight )
			DEFAULT_PROPERTY( m_nPctWidthRelative )
			DEFAULT_PROPERTY( m_nPctHeightRelative )
			DEFAULT_PROPERTY( m_nColStart )
			DEFAULT_PROPERTY( m_nColSpan )

			//Object Type
			DEFAULT_PROPERTY( m_bIsBullet )
			DEFAULT_PROPERTY( m_nRotation )
			DEFAULT_PROPERTY( m_bFlipV )
			DEFAULT_PROPERTY( m_bFlipH )
			DEFAULT_PROPERTY( m_nShapeType )
			DEFAULT_PROPERTY( m_nWrapDistLeft )
			DEFAULT_PROPERTY( m_nWrapDistTop )
			DEFAULT_PROPERTY( m_nWrapDistRight )
			DEFAULT_PROPERTY( m_nWrapDistBottom )

			//m_bBehindDocument = -1;
			DEFAULT_PROPERTY( m_bHidden )

			//Text box
			DEFAULT_PROPERTY_DEF( m_nTexpLeft, 91440 )
			DEFAULT_PROPERTY_DEF( m_nTexpTop, 45720 )
			DEFAULT_PROPERTY_DEF( m_nTexpRight, 91440 )
			DEFAULT_PROPERTY_DEF( m_nTexpBottom, 45720 )

			//Geometry
			DEFAULT_PROPERTY( m_nAdjustValue )
			DEFAULT_PROPERTY( m_nAdjustValue2 )
			DEFAULT_PROPERTY( m_nAdjustValue3 )
			DEFAULT_PROPERTY( m_nAdjustValue4 )
			DEFAULT_PROPERTY( m_nAdjustValue5 )
			DEFAULT_PROPERTY( m_nAdjustValue6 )
			DEFAULT_PROPERTY( m_nAdjustValue7 )
			DEFAULT_PROPERTY( m_nAdjustValue8 )
			DEFAULT_PROPERTY( m_nAdjustValue9 )
			DEFAULT_PROPERTY( m_nAdjustValue10 )

			//WordArt Effects
			DEFAULT_PROPERTY( m_nCropFromTop )
			DEFAULT_PROPERTY( m_nCropFromBottom )
			DEFAULT_PROPERTY( m_nCropFromLeft )
			DEFAULT_PROPERTY( m_nCropFromRight )

			//Grouped Shapes
			DEFAULT_PROPERTY( m_nGroupBottom )
			DEFAULT_PROPERTY( m_nGroupLeft )
			DEFAULT_PROPERTY( m_nGroupRight )
			DEFAULT_PROPERTY( m_nGroupTop )
			DEFAULT_PROPERTY( m_nRelBottom )
			DEFAULT_PROPERTY( m_nRelLeft )
			DEFAULT_PROPERTY( m_nRelRight )
			DEFAULT_PROPERTY( m_nRelTop )
			DEFAULT_PROPERTY( m_nRelRotation )
			DEFAULT_PROPERTY( m_nRelZOrder )

			//Rehydration
			m_sMetroBlob = _T("");
			m_sMetroBlobRels = _T("");
			m_sMetroBlobData = _T("");
			//Connectors
			DEFAULT_PROPERTY( m_nConnectionType )
			DEFAULT_PROPERTY( m_nConnectorStyle )

			//Fill
			DEFAULT_PROPERTY_DEF( m_bFilled, true )
			//Line
			DEFAULT_PROPERTY_DEF( m_bLine, true )
			DEFAULT_PROPERTY( m_nLineStartArrow )
			DEFAULT_PROPERTY( m_nLineStartArrowWidth )
			DEFAULT_PROPERTY( m_nLineStartArrowLength )
			DEFAULT_PROPERTY( m_nLineEndArrow )
			DEFAULT_PROPERTY( m_nLineEndArrowWidth )
			DEFAULT_PROPERTY( m_nLineEndArrowLength )

			m_aTextItems = TextItemContainerPtr();
			m_oPicture = RtfPicturePtr();
			m_bIsOle = false;
		}
public: CString RenderToRtf(RenderParameter oRenderParameter);
private: CString RenderToRtfShapeProperty(RenderParameter oRenderParameter);
public: CString RenderToOOX(RenderParameter oRenderParameter);
public: CString RenderToOOXBegin(RenderParameter oRenderParameter);
public: CString RenderToOOXEnd(RenderParameter oRenderParameter);
public: void ToRtfRotation( int nAngel , int &nLeft, int &nTop, int& nRight, int& nBottom )
		{
			//������������ �� 45 ��������
			nAngel -= 45;
			//������ ���� �� 0 �� 360
			nAngel = nAngel % 360;
			if( nAngel < 0 )
				nAngel += 360;
			int nQuater = nAngel / 90; // ���������� ��������
			if( 0 == nQuater || 2 == nQuater )
			{
				//������������ ������������ ������ �� 90 �������� �������
				int nCenterX = ( nLeft + nRight ) / 2;
				int nCenterY = ( nTop + nBottom ) / 2;
				int nWidth = nRight - nLeft;
				int nHeight = nBottom - nTop;

				nLeft = nCenterX - nHeight / 2;
				nRight = nCenterX + nHeight / 2;
				nTop = nCenterY - nWidth / 2;
				nBottom = nCenterY + nWidth / 2;
			}
		}
};
typedef boost::shared_ptr<RtfShape> RtfShapePtr;
class RtfShapeGroup : public RtfShape, public ItemContainer<RtfShapePtr>
{
public: CString RenderToRtf(RenderParameter oRenderParameter);
public: CString RenderToOOX(RenderParameter oRenderParameter);
public: bool IsValid()
		{
			return true;
		}
};
typedef boost::shared_ptr<RtfShapeGroup> RtfShapeGroupPtr;
