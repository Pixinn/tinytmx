#include "tinytmxText.hpp"
#include "tinytmxColor.hpp"
#include "tinyxml2.h"
#include <cstdlib>


namespace tinytmx {
    Text::Text()
            : font_family("sans-serif"), pixel_size(16), wrap(false), color(new Color("#000000")), bold(false),
              italic(false), underline(false), strikeout(false), kerning(true),
              horizontal_alignment(HorizontalAlignment::LEFT), vertical_alignment(VerticalAlignment::TOP) {
    }

    Text::~Text() {
        if (color) {
            delete color;
            color = nullptr;
        }
    }

    void Text::Parse(const tinyxml2::XMLNode *textNode) {
        const tinyxml2::XMLElement *textElement = textNode->ToElement();

        contents = std::string(textElement->GetText() ? textElement->GetText() : "");
        if (textElement->FindAttribute("fontfamily")) {
            font_family = std::string(textElement->Attribute("fontfamily"));
        }
        textElement->QueryIntAttribute("pixelsize", &pixel_size);
        textElement->QueryBoolAttribute("wrap", &wrap);
        textElement->QueryBoolAttribute("bold", &bold);
        textElement->QueryBoolAttribute("italic", &italic);
        textElement->QueryBoolAttribute("underline", &underline);
        textElement->QueryBoolAttribute("strikeout", &strikeout);
        textElement->QueryBoolAttribute("kerning", &kerning);

        if (textElement->FindAttribute("halign")) {
            const char* halignAsCString = textElement->Attribute("halign");

            if (std::strcmp(halignAsCString, "left") == 0) {
                horizontal_alignment = HorizontalAlignment::LEFT;
            } else if (std::strcmp(halignAsCString, "center") == 0) {
                horizontal_alignment = HorizontalAlignment::HCENTER;
            } else if (std::strcmp(halignAsCString, "right") == 0) {
                horizontal_alignment = HorizontalAlignment::RIGHT;
            } else if (std::strcmp(halignAsCString, "justify") == 0) {
                horizontal_alignment = HorizontalAlignment::JUSTIFY;
            }
        }

        if (textElement->FindAttribute("valign")) {
            const char* valignAsCString = textElement->Attribute("valign");

            if (std::strcmp(valignAsCString, "top") == 0) {
                vertical_alignment = VerticalAlignment::TOP;
            } else if (std::strcmp(valignAsCString, "center") == 0) {
                vertical_alignment = VerticalAlignment::VCENTER;
            } else if (std::strcmp(valignAsCString, "bottom") == 0) {
                vertical_alignment = VerticalAlignment::BOTTOM;
            }
        }

        if (textElement->FindAttribute("color"))
            color = new Color(textElement->Attribute("color"));
    }
}
