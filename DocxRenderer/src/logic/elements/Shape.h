#pragma once
#include "Paragraph.h"
#include "../../resources/ImageInfo.h"
#include "../../resources/LinesTable.h"
#include "../../resources/VectorGraphics.h"

namespace NSDocxRenderer
{
    enum class eGraphicsType
    {
        gtUnknown,
        gtRectangle,
        gtCurve,
        gtComplicatedFigure,
        gtNoGraphics,
    };

    class CShape : public CBaseItem
    {
        public:
            enum class eShapeType
            {
                stUnknown,
                stTextBox,
                stPicture,
                stVectorGraphics,
                stVectorTexture,
                stGroup,
                stCanvas,
            };

        public:
            eShapeType              m_eType {eShapeType::stUnknown};
            std::wstring            m_strPath {L""};
            NSStructures::CBrush	m_oBrush;
            NSStructures::CPen		m_oPen;
            double                  m_dRotate {0.0};

            bool m_bIsNoFill {true};
            bool m_bIsNoStroke {true};
            bool m_bIsBehindDoc {false};

            eGraphicsType   m_eGraphicsType {eGraphicsType::gtUnknown};
            eSimpleLineType m_eSimpleLineType {eSimpleLineType::sltUnknown};
            eLineType       m_eLineType {eLineType::ltUnknown};

            std::vector<CParagraph*> m_arParagraphs;

            std::shared_ptr<CImageInfo> m_pImageInfo {nullptr};

            //Показывает, что есть отношение графики к тексту (подчеркивания/зачеркивания/выделение).
            //note Пока сюда записывается указатель на символ с наибольшем размером шрифта.
            CContText* m_pCont {nullptr};

        private:
            UINT m_nShapeId {0};

        public:
            CShape();
            virtual ~CShape();
            virtual void Clear() override final;

            CShape(std::shared_ptr<CImageInfo> pInfo, const std::wstring& strDstMedia);

            void GetDataFromVector(const CVectorGraphics& oVector, const LONG& lTypee);

            void WritePath(const CVectorGraphics& oVector);

            void DetermineGraphicsType(double dWidth, double dHeight, size_t nPeacks, size_t nCurves);

            bool IsItFitLine();
            bool IsCorrelated(const CShape* pShape);
            void ChangeGeometryOfDesiredShape(CShape* pShape);

            void DetermineLineType(CShape* pShape = nullptr, bool bIsLast = false);

            virtual void ToXml(NSStringUtils::CStringBuilder& oWriter) override final;
            void BuildGeneralProperties(NSStringUtils::CStringBuilder &oWriter);
            void BuildSpecificProperties(NSStringUtils::CStringBuilder &oWriter);
            void BuildShapeProperties(NSStringUtils::CStringBuilder &oWriter);
            void BuildPictureProperties(NSStringUtils::CStringBuilder &oWriter);
            void BuildGroupProperties(NSStringUtils::CStringBuilder &oWriter);
            void BuildCanvasProperties(NSStringUtils::CStringBuilder &oWriter);
            void BuildGraphicProperties(NSStringUtils::CStringBuilder &oWriter);
            void BuildTextBox(NSStringUtils::CStringBuilder &oWriter);

        private:
            UINT GenerateShapeId();
            UINT GenerateRelativeHeight();
    };
}
