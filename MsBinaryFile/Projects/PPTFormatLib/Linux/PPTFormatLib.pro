#-------------------------------------------------
#
# Project created by QtCreator
#
#-------------------------------------------------

QT       -= core gui

TARGET = PptFormatLib
TEMPLATE = lib
CONFIG += staticlib

CORE_ROOT_DIR = $$PWD/../../../..
PWD_ROOT_DIR = $$PWD

CONFIG += core_x2t
include(../../../../Common/base.pri)

#BOOST
include($$PWD/../../../../Common/3dParty/boost/boost.pri)

DEFINES +=  UNICODE \
        _UNICODE \
        _PRESENTATION_WRITER_ \
        _SVG_CONVERT_TO_IMAGE_  \
        DONT_WRITE_EMBEDDED_FONTS
        #DISABLE_FILE_DOWNLOADER

HEADERS += \
	../../../PptFile/Main/PPTFormatLib.h \
	../../../PptFile/Converter/Animation/AnimationParser.h \
	../../../PptFile/Converter/Animation/Animation_1995.h \
	../../../PptFile/Converter/Animation/TimingExeption.h \
	../../../PptFile/Converter/Animation/TimingUtils.h \
	../../../PptFile/Converter/Animation/Timing_1995.h \
	../../../PptFile/Converter/Animation/Timing_2010.h \
	../../../PptFile/Converter/Animation/hashcode10.h \
	../../../PptFile/Converter/Animation/intermediate_anim.h \
	../../../PptFile/Converter/timing.h \
	../../../PptFile/Converter/transition.h \
	../../../PptFile/Enums/RecordType.h \
	../../../PptFile/Enums/_includer.h \
	../../../PptFile/Enums/enums.h \
	../../../PptFile/PPTFormatLib.h \
	../../../PptFile/PPTXWriter/BulletsConverter.h \
	../../../PptFile/PPTXWriter/TableWriter.h \
	../../../PptFile/PPTXWriter/TxBodyConverter.h \
	../../../PptFile/Reader/ClassesAtom.h \
	../../../PptFile/Reader/CommonZLib.h \
	../../../PptFile/Reader/ExtXmlUtils.h \
	../../../PptFile/Reader/PPTDocumentInfo.h \
	../../../PptFile/Reader/PPTDocumentInfoOneUser.h \
	../../../PptFile/Reader/PPTFileDefines.h \
	../../../PptFile/Reader/PPTFileReader.h \
	../../../PptFile/Reader/ReadStructures.h \
	../../../PptFile/Reader/Records.h \
	../../../PptFile/Reader/RoundTripExtractor.h \
	../../../PptFile/Reader/Slide.h \
	../../../PptFile/Reader/SlideInfo.h \
	../../../PptFile/Reader/SlidePersist.h \
	../../../PptFile/Records/Animations/AnimationInfoAtom.h \
	../../../PptFile/Records/Animations/AnimationInfoContainer.h \
	../../../PptFile/Records/Animations/BuildAtom.h \
	../../../PptFile/Records/Animations/BuildListContainer.h \
	../../../PptFile/Records/Animations/BuildListSubContainer.h \
	../../../PptFile/Records/Animations/ChartBuildAtom.h \
	../../../PptFile/Records/Animations/ChartBuildContainer.h \
	../../../PptFile/Records/Animations/ClientVisualElementContainer.h \
	../../../PptFile/Records/Animations/DiagramBuildAtom.h \
	../../../PptFile/Records/Animations/DiagramBuildContainer.h \
	../../../PptFile/Records/Animations/ExtTimeNodeContainer.h \
	../../../PptFile/Records/Animations/HashCode10Atom.h \
	../../../PptFile/Records/Animations/LevelInfoAtom.h \
	../../../PptFile/Records/Animations/ParaBuildAtom.h \
	../../../PptFile/Records/Animations/ParaBuildContainer.h \
	../../../PptFile/Records/Animations/ParaBuildLevel.h \
	../../../PptFile/Records/Animations/SubEffectContainer.h \
	../../../PptFile/Records/Animations/TimeAnimateBehaviorAtom.h \
	../../../PptFile/Records/Animations/TimeAnimateBehaviorContainer.h \
	../../../PptFile/Records/Animations/TimeAnimateColor.h \
	../../../PptFile/Records/Animations/TimeAnimateColorBy.h \
	../../../PptFile/Records/Animations/TimeAnimationValueAtom.h \
	../../../PptFile/Records/Animations/TimeAnimationValueListContainer.h \
	../../../PptFile/Records/Animations/TimeAnimationValueListEntry.h \
	../../../PptFile/Records/Animations/TimeBehaviorAtom.h \
	../../../PptFile/Records/Animations/TimeBehaviorContainer.h \
	../../../PptFile/Records/Animations/TimeColorBehaviorAtom.h \
	../../../PptFile/Records/Animations/TimeColorBehaviorContainer.h \
	../../../PptFile/Records/Animations/TimeCommandBehaviorAtom.h \
	../../../PptFile/Records/Animations/TimeCommandBehaviorContainer.h \
	../../../PptFile/Records/Animations/TimeConditionAtom.h \
	../../../PptFile/Records/Animations/TimeConditionContainer.h \
	../../../PptFile/Records/Animations/TimeDisplayType.h \
	../../../PptFile/Records/Animations/TimeEffectBehaviorAtom.h \
	../../../PptFile/Records/Animations/TimeEffectBehaviorContainer.h \
	../../../PptFile/Records/Animations/TimeEffectID.h \
	../../../PptFile/Records/Animations/TimeEffectNodeType.h \
	../../../PptFile/Records/Animations/TimeEffectType.h \
	../../../PptFile/Records/Animations/TimeGroupID.h \
	../../../PptFile/Records/Animations/TimeIterateDataAtom.h \
	../../../PptFile/Records/Animations/TimeMasterRelType.h \
	../../../PptFile/Records/Animations/TimeModifierAtom.h \
	../../../PptFile/Records/Animations/TimeMotionBehaviorAtom.h \
	../../../PptFile/Records/Animations/TimeMotionBehaviorContainer.h \
	../../../PptFile/Records/Animations/TimeNodeAtom.h \
	../../../PptFile/Records/Animations/TimeNodeTimeFilter.h \
	../../../PptFile/Records/Animations/TimePropertyList4TimeBehavior.h \
	../../../PptFile/Records/Animations/TimePropertyList4TimeNodeContainer.h \
	../../../PptFile/Records/Animations/TimeRotationBehaviorAtom.h \
	../../../PptFile/Records/Animations/TimeRotationBehaviorContainer.h \
	../../../PptFile/Records/Animations/TimeScaleBehaviorAtom.h \
	../../../PptFile/Records/Animations/TimeScaleBehaviorContainer.h \
	../../../PptFile/Records/Animations/TimeSequenceDataAtom.h \
	../../../PptFile/Records/Animations/TimeSetBehaviorAtom.h \
	../../../PptFile/Records/Animations/TimeSetBehaviorContainer.h \
	../../../PptFile/Records/Animations/TimeStringListContainer.h \
	../../../PptFile/Records/Animations/TimeVariant.h \
	../../../PptFile/Records/Animations/TimeVariant4Behavior.h \
	../../../PptFile/Records/Animations/VisualPageAtom.h \
	../../../PptFile/Records/Animations/VisualShapeAtom.h \
	../../../PptFile/Records/Animations/VisualShapeChartElementAtom.h \
	../../../PptFile/Records/Animations/VisualShapeGeneralAtom.h \
	../../../PptFile/Records/Animations/VisualSoundAtom.h \
	../../../PptFile/Records/Animations/_includer.h \
	../../../PptFile/Records/BlipCollection9Container.h \
	../../../PptFile/Records/BlipEntityAtom.h \
	../../../PptFile/Records/BookmarkEntityAtom.h \
	../../../PptFile/Records/BookmarkSeedAtom.h \
	../../../PptFile/Records/BuildAtom.h \
	../../../PptFile/Records/DocInfoListContainer.h \
	../../../PptFile/Records/DocProgTagsContainer.h \
	../../../PptFile/Records/MouseInteractiveInfoContainer.h \
	../../../PptFile/Records/OfficeArtClientData.h \
	../../../PptFile/Records/OfficeArtClientTextbox.h \
	../../../PptFile/Records/PlaceHolderAtom.h \
	../../../PptFile/Records/RoundTrip.h \
	../../../PptFile/Records/ShapeProgBinaryTagSubContainerOrAtom.h \
	../../../PptFile/Records/CFMasks.h \
	../../../PptFile/Records/ColorSchemeAtom.h \
	../../../PptFile/Records/CString.h \
	../../../PptFile/Records/CurrentUserAtom.h \
	../../../PptFile/Records/DocRoutingSlipAtom.h \
	../../../PptFile/Records/DocumentAtom.h \
	../../../PptFile/Records/DocumentRecords.h \
	../../../PptFile/Records/DocumentTextInfo.h \
	../../../PptFile/Records/EndDocument.h \
	../../../PptFile/Records/ExCDAudioContainer.h \
	../../../PptFile/Records/ExControlAtom.h \
	../../../PptFile/Records/ExHyperlinkAtom.h \
	../../../PptFile/Records/ExMediaAtom.h \
	../../../PptFile/Records/ExMIDIAudioContainer.h \
	../../../PptFile/Records/ExObjListAtom.h \
	../../../PptFile/Records/ExObjListContainer.h \
	../../../PptFile/Records/ExObjRefAtom.h \
	../../../PptFile/Records/ExOleEmbedAtom.h \
	../../../PptFile/Records/ExOleLinkAtom.h \
	../../../PptFile/Records/ExOleObjAtom.h \
	../../../PptFile/Records/ExVideoContainer.h \
	../../../PptFile/Records/ExWAVAudioEmbeddedContainer.h \
	../../../PptFile/Records/ExWAVAudioLinkContainer.h \
	../../../PptFile/Records/FontEntityAtom.h \
	../../../PptFile/Records/GridSpacing10Atom.h \
	../../../PptFile/Records/GuideAtom.h \
	../../../PptFile/Records/HeadersFootersAtom.h \
	../../../PptFile/Records/InteractiveInfoAtom.h \
	../../../PptFile/Records/KinsokuAtom.h \
	../../../PptFile/Records/KinsokuContainer.h \
	../../../PptFile/Records/KinsokuFollowingAtom.h \
	../../../PptFile/Records/KinsokuLeadingAtom.h \
	../../../PptFile/Records/MasterPersistAtom.h \
	../../../PptFile/Records/MasterTextPropAtom.h \
	../../../PptFile/Records/MetafileBlob.h \
	../../../PptFile/Records/MouseTextInteractiveInfoAtom.h \
	../../../PptFile/Records/NamedShowSlidesAtom.h \
	../../../PptFile/Records/NormalViewSetInfoAtom.h \
	../../../PptFile/Records/NotesAtom.h \
	../../../PptFile/Records/NotesPersistAtom.h \
	../../../PptFile/Records/NoZoomViewInfoAtom.h \
	../../../PptFile/Records/OutlineTextRefAtom.h \
	../../../PptFile/Records/FontCollection10Container.h \
	../../../PptFile/Records/FontEmbedFlags10Atom.h \
	../../../PptFile/Records/OutlineTextProps9Container.h \
	../../../PptFile/Records/OutlineTextPropsHeaderExAtom.h \
	../../../PptFile/Records/PFMasks.h \
	../../../PptFile/Records/PersistDirectoryAtom.h \
	../../../PptFile/Records/PlaceHolderAtom.h \
	../../../PptFile/Records/ProgStringTagContainer.h \
	../../../PptFile/Records/RecordsIncluder.h \
	../../../PptFile/Records/ShapeFlags10Atom.h \
	../../../PptFile/Records/ShapeFlagsAtom.h \
	../../../PptFile/Records/Comment10Container.h \
	../../../PptFile/Records/LinkedShape10Atom.h \
	../../../PptFile/Records/LinkedSlide10Atom.h \
	../../../PptFile/Records/SlideFlags10Atom.h \
	../../../PptFile/Records/SlideProgTagsContainer.h \
	../../../PptFile/Records/SlideTime10Atom.h \
	../../../PptFile/Records/SlideAtom.h \
	../../../PptFile/Records/SlideColorSchemeAtom.h \
	../../../PptFile/Records/SlideContainer.h \
	../../../PptFile/Records/SlideListWithText.h \
	../../../PptFile/Records/SlidePersistAtom.h \
	../../../PptFile/Records/SlideProgTagsContainer.h \
	../../../PptFile/Records/SlideViewInfoAtom.h \
	../../../PptFile/Records/SoundCollAtom.h \
	../../../PptFile/Records/SoundCollectionContainer.h \
	../../../PptFile/Records/SoundContainer.h \
	../../../PptFile/Records/SoundDataBlob.h \
	../../../PptFile/Records/SSDocInfoAtom.h \
	../../../PptFile/Records/SSlideLayoutAtom.h \
	../../../PptFile/Records/SSSlideInfoAtom.h \
	../../../PptFile/Records/StyleTextPropAtom.h \
	../../../PptFile/Records/StyleTextProp10Atom.h \
	../../../PptFile/Records/StyleTextProp11Atom.h \
	../../../PptFile/Records/StyleTextProp9Atom.h \
	../../../PptFile/Records/TextCFException10.h \
	../../../PptFile/Records/TextCFException9.h \
	../../../PptFile/Records/TextDefaults9Atom.h \
	../../../PptFile/Records/TextMasterStyle9Atom.h \
	../../../PptFile/Records/TextMasterStyle9Level.h \
	../../../PptFile/Records/TextSIException.h \
	../../../PptFile/Records/TextBookmarkAtom.h \
	../../../PptFile/Records/TextBytesAtom.h \
	../../../PptFile/Records/TextCFExceptionAtom.h \
	../../../PptFile/Records/TextCharsAtom.h \
	../../../PptFile/Records/TextFullSettings.h \
	../../../PptFile/Records/TextHeaderAtom.h \
	../../../PptFile/Records/TextInteractiveInfoAtom.h \
	../../../PptFile/Records/TextMasterStyle9Atom.h \
	../../../PptFile/Records/TextMasterStyle9Level.h \
	../../../PptFile/Records/TextMasterStyleAtom.h \
	../../../PptFile/Records/TextPFException9.h \
	../../../PptFile/Records/TextPFExceptionAtom.h \
	../../../PptFile/Records/TextRulerAtom.h \
	../../../PptFile/Records/TextSIExceptionAtom.h \
	../../../PptFile/Records/TextSpecInfoAtom.h \
	../../../PptFile/Records/UserEditAtom.h \
	../../../PptFile/Records/VBAInfoAtom.h \
	../../../PptFile/Records/ViewInfoAtom.h \
	../../../PptFile/Records/ZoomViewInfoAtom.h \
	../../../PptFile/Records/Animations/AnimationTypes.h \
	../../../PptFile/Records/Drawing/BlipStoreContainer.h \
	../../../PptFile/Records/Drawing/BlipStoreEntry.h \
	../../../PptFile/Records/Drawing/ChildAnchor.h \
	../../../PptFile/Records/Drawing/ClientAnchor.h \
	../../../PptFile/Records/Drawing/DrawingContainer.h \
	../../../PptFile/Records/Drawing/DrawingGroup.h \
	../../../PptFile/Records/Drawing/DrawingRecord.h \
	../../../PptFile/Records/Drawing/GroupShape.h \
	../../../PptFile/Records/Drawing/GroupShapeContainer.h \
	../../../PptFile/Records/Drawing/RegGroupItems.h \
	../../../PptFile/Records/Drawing/Shape.h \
	../../../PptFile/Records/Drawing/ShapeContainer.h \
	../../../PptFile/Records/Drawing/ShapeProperties.h \
	../../../PptFile/Records/Drawing/TextBox.h \
	../../../PptFile/Records/Drawing/ArtBlip.h \
	../../../PptFile/PPTXWriter/Converter.h \
	../../../PptFile/PPTXWriter/ImageManager.h \
	../../../PptFile/PPTXWriter/ShapeWriter.h \
	../../../PptFile/PPTXWriter/StylesWriter.h \
	../../../PptFile/Drawing/Element.h \
	../../../PptFile/Drawing/Elements.h \
	../../../PptFile/Drawing/Layout.h \
	../../../PptFile/Drawing/Slide.h \
	../../../PptFile/Drawing/TextAttributesEx.h \
	../../../PptFile/Drawing/TextStructures.h \
	../../../PptFile/Drawing/Theme.h \
	../../../PptFile/Structures/ColorIndex.h \
	../../../PptFile/Structures/ColorIndexStruct.h \
	../../../PptFile/Structures/ColorStruct.h \
	../../../PptFile/Structures/DateTimeStruct.h \
	../../../PptFile/Structures/IStruct.h \
	../../../PptFile/Structures/PointStruct.h \
	../../../PptFile/Structures/RatioStruct.h \
	../../../PptFile/Structures/RectStruct.h \
	../../../PptFile/Structures/ScalingStruct.h \
	../../../PptFile/Structures/SmallRectStruct.h \
	../../../PptFile/Structures/TmsfTimeStruct.h \
	../../../PptFile/Structures/WideColorStruct.h \
	../../../PptFile/Structures/_includer.h

core_release {
SOURCES += \
	ppt_format_logic.cpp
}

core_debug {
SOURCES += \
	../../../PptFile/Enums/RecordType.cpp \
	../../../PptFile/Enums/RecordType.cpp \
        \
	../../../PptFile/Reader/ReadStructures.cpp \
	../../../PptFile/Reader/RoundTripExtractor.cpp \
	../../../PptFile/Reader/PPTDocumentInfoOneUser.cpp \
	../../../PptFile/Reader/Records.cpp \
	../../../PptFile/Reader/PPTFileReader.cpp \
	../../../PptFile/Reader/SlidePersist.cpp \
        \
	../../../PptFile/PPTXWriter/Converter.cpp \
	../../../PptFile/PPTXWriter/ShapeWriter.cpp \
        ../../../PptFile/PPTXWriter/StylesWriter.cpp \
        ../../../PptFile/PPTXWriter/TableWriter.cpp \
	../../../PptFile/PPTXWriter/TxBodyConverter.cpp \
        ../../../PptFile/PPTXWriter/ImageManager.cpp \
        ../../../PptFile/PPTXWriter/BulletsConverter.cpp \
        \
        ../../../PptFile/Drawing/Element.cpp \
        ../../../PptFile/Drawing/Elements.cpp \
        ../../../PptFile/Drawing/Layout.cpp \
        ../../../PptFile/Drawing/Slide.cpp \
        ../../../PptFile/Drawing/TextStructures.cpp \
        ../../../PptFile/Drawing/TextAttributesEx.cpp \
        \
        ../../../PptFile/Converter/Animation/AnimationParser.cpp \
	../../../PptFile/Converter/Animation/Animation_1995.cpp \
	../../../PptFile/Converter/Animation/TimingUtils.cpp \
	../../../PptFile/Converter/Animation/Timing_1995.cpp \
	../../../PptFile/Converter/Animation/Timing_2010.cpp \
	../../../PptFile/Converter/Animation/hashcode10.cpp \
	../../../PptFile/Converter/Animation/intermediate_anim.cpp \
	../../../PptFile/Converter/timing.cpp \
	../../../PptFile/Converter/transition.cpp \
        \
        ../../../PptFile/Records/Drawing/ArtBlip.cpp \
        ../../../PptFile/Records/Drawing/ShapeContainer.cpp \
        ../../../PptFile/Records/Animations/TimeVariant.cpp \
        ../../../PptFile/Records/BlipEntityAtom.cpp \
        ../../../PptFile/Records/Animations/AnimationInfoAtom.cpp \
        ../../../PptFile/Records/Animations/AnimationInfoContainer.cpp \
        ../../../PptFile/Records/Animations/BuildAtom.cpp \
        ../../../PptFile/Records/Animations/BuildListSubContainer.cpp \
        ../../../PptFile/Records/Animations/ChartBuildAtom.cpp \
        ../../../PptFile/Records/Animations/ChartBuildContainer.cpp \
        ../../../PptFile/Records/Animations/ClientVisualElementContainer.cpp \
        ../../../PptFile/Records/Animations/DiagramBuildAtom.cpp \
        ../../../PptFile/Records/Animations/DiagramBuildContainer.cpp \
        ../../../PptFile/Records/Animations/ExtTimeNodeContainer.cpp \
        ../../../PptFile/Records/Animations/HashCode10Atom.cpp \
        ../../../PptFile/Records/Animations/LevelInfoAtom.cpp \
        ../../../PptFile/Records/Animations/ParaBuildAtom.cpp \
        ../../../PptFile/Records/Animations/ParaBuildContainer.cpp \
        ../../../PptFile/Records/Animations/ParaBuildLevel.cpp \
        ../../../PptFile/Records/Animations/SubEffectContainer.cpp \
        ../../../PptFile/Records/Animations/TimeAnimateBehaviorAtom.cpp \
        ../../../PptFile/Records/Animations/TimeAnimateBehaviorContainer.cpp \
        ../../../PptFile/Records/Animations/TimeAnimateColor.cpp \
        ../../../PptFile/Records/Animations/TimeAnimateColorBy.cpp \
        ../../../PptFile/Records/Animations/TimeAnimationValueAtom.cpp \
        ../../../PptFile/Records/Animations/TimeAnimationValueListContainer.cpp \
        ../../../PptFile/Records/Animations/TimeAnimationValueListEntry.cpp \
        ../../../PptFile/Records/Animations/TimeBehaviorAtom.cpp \
        ../../../PptFile/Records/Animations/TimeBehaviorContainer.cpp \
        ../../../PptFile/Records/Animations/TimeColorBehaviorAtom.cpp \
        ../../../PptFile/Records/Animations/TimeColorBehaviorContainer.cpp \
        ../../../PptFile/Records/Animations/TimeCommandBehaviorAtom.cpp \
        ../../../PptFile/Records/Animations/TimeCommandBehaviorContainer.cpp \
        ../../../PptFile/Records/Animations/TimeConditionAtom.cpp \
        ../../../PptFile/Records/Animations/TimeConditionContainer.cpp \
        ../../../PptFile/Records/Animations/TimeEffectBehaviorAtom.cpp \
        ../../../PptFile/Records/Animations/TimeEffectBehaviorContainer.cpp \
        ../../../PptFile/Records/Animations/TimeIterateDataAtom.cpp \
        ../../../PptFile/Records/Animations/TimeModifierAtom.cpp \
        ../../../PptFile/Records/Animations/TimeMotionBehaviorAtom.cpp \
        ../../../PptFile/Records/Animations/TimeMotionBehaviorContainer.cpp \
        ../../../PptFile/Records/Animations/TimeNodeAtom.cpp \
        ../../../PptFile/Records/Animations/TimePropertyList4TimeBehavior.cpp \
        ../../../PptFile/Records/Animations/TimePropertyList4TimeNodeContainer.cpp \
        ../../../PptFile/Records/Animations/TimeRotationBehaviorAtom.cpp \
        ../../../PptFile/Records/Animations/TimeRotationBehaviorContainer.cpp \
        ../../../PptFile/Records/Animations/TimeScaleBehaviorAtom.cpp \
        ../../../PptFile/Records/Animations/TimeScaleBehaviorContainer.cpp \
        ../../../PptFile/Records/Animations/TimeSequenceDataAtom.cpp \
        ../../../PptFile/Records/Animations/TimeSetBehaviorAtom.cpp \
        ../../../PptFile/Records/Animations/TimeSetBehaviorContainer.cpp \
        ../../../PptFile/Records/Animations/TimeStringListContainer.cpp \
        ../../../PptFile/Records/Animations/TimeVariant4Behavior.cpp \
        ../../../PptFile/Records/Animations/VisualPageAtom.cpp \
        ../../../PptFile/Records/Animations/VisualShapeAtom.cpp \
        ../../../PptFile/Records/Animations/VisualShapeChartElementAtom.cpp \
        ../../../PptFile/Records/Animations/VisualShapeGeneralAtom.cpp \
        ../../../PptFile/Records/Animations/VisualSoundAtom.cpp \
        ../../../PptFile/Records/BlipCollection9Container.cpp \
        ../../../PptFile/Records/BookmarkEntityAtom.cpp \
        ../../../PptFile/Records/BookmarkSeedAtom.cpp \
        ../../../PptFile/Records/BuildAtom.cpp \
        ../../../PptFile/Records/CFMasks.cpp \
        ../../../PptFile/Records/CString.cpp \
        ../../../PptFile/Records/ColorSchemeAtom.cpp \
        ../../../PptFile/Records/Comment10Container.cpp \
        ../../../PptFile/Records/CurrentUserAtom.cpp \
        ../../../PptFile/Records/DocInfoListContainer.cpp \
        ../../../PptFile/Records/DocProgTagsContainer.cpp \
        ../../../PptFile/Records/DocRoutingSlipAtom.cpp \
        ../../../PptFile/Records/DocumentAtom.cpp \
        ../../../PptFile/Records/DocumentRecords.cpp \
        ../../../PptFile/Records/DocumentTextInfo.cpp \
        ../../../PptFile/Records/Drawing/BlipStoreContainer.cpp \
        ../../../PptFile/Records/Drawing/BlipStoreEntry.cpp \
        ../../../PptFile/Records/Drawing/ChildAnchor.cpp \
        ../../../PptFile/Records/Drawing/ClientAnchor.cpp \
        ../../../PptFile/Records/Drawing/DrawingContainer.cpp \
        ../../../PptFile/Records/Drawing/DrawingGroup.cpp \
        ../../../PptFile/Records/Drawing/DrawingRecord.cpp \
        ../../../PptFile/Records/Drawing/GroupShape.cpp \
        ../../../PptFile/Records/Drawing/Shape.cpp \
        ../../../PptFile/Records/Drawing/ShapeProperties.cpp \
        ../../../PptFile/Records/Drawing/TextBox.cpp \
        ../../../PptFile/Records/EndDocument.cpp \
        ../../../PptFile/Records/ExCDAudioContainer.cpp \
        ../../../PptFile/Records/ExControlAtom.cpp \
        ../../../PptFile/Records/ExHyperlinkAtom.cpp \
        ../../../PptFile/Records/ExMIDIAudioContainer.cpp \
        ../../../PptFile/Records/ExMediaAtom.cpp \
        ../../../PptFile/Records/ExObjListAtom.cpp \
        ../../../PptFile/Records/ExObjListContainer.cpp \
        ../../../PptFile/Records/ExObjRefAtom.cpp \
        ../../../PptFile/Records/ExOleEmbedAtom.cpp \
        ../../../PptFile/Records/ExOleLinkAtom.cpp \
        ../../../PptFile/Records/ExOleObjAtom.cpp \
        ../../../PptFile/Records/ExVideoContainer.cpp \
        ../../../PptFile/Records/ExWAVAudioEmbeddedContainer.cpp \
        ../../../PptFile/Records/ExWAVAudioLinkContainer.cpp \
        ../../../PptFile/Records/FontCollection10Container.cpp \
        ../../../PptFile/Records/FontEmbedFlags10Atom.cpp \
        ../../../PptFile/Records/FontEntityAtom.cpp \
        ../../../PptFile/Records/GridSpacing10Atom.cpp \
        ../../../PptFile/Records/GuideAtom.cpp \
        ../../../PptFile/Records/HeadersFootersAtom.cpp \
        ../../../PptFile/Records/InteractiveInfoAtom.cpp \
        ../../../PptFile/Records/KinsokuAtom.cpp \
        ../../../PptFile/Records/KinsokuContainer.cpp \
        ../../../PptFile/Records/KinsokuFollowingAtom.cpp \
        ../../../PptFile/Records/KinsokuLeadingAtom.cpp \
        ../../../PptFile/Records/LinkedShape10Atom.cpp \
        ../../../PptFile/Records/LinkedSlide10Atom.cpp \
        ../../../PptFile/Records/MasterPersistAtom.cpp \
        ../../../PptFile/Records/MasterTextPropAtom.cpp \
        ../../../PptFile/Records/MetafileBlob.cpp \
        ../../../PptFile/Records/MouseInteractiveInfoContainer.cpp \
        ../../../PptFile/Records/MouseTextInteractiveInfoAtom.cpp \
        ../../../PptFile/Records/NamedShowSlidesAtom.cpp

}

SOURCES += \
	../../../PptFile/Main/PPTFormatLib.cpp \
	../../../../Common/3dParty/pole/pole.cpp
