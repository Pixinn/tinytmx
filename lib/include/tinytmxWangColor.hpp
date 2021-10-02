#ifndef TINYTMX_TINYTMXWANGCOLOR_HPP
#define TINYTMX_TINYTMXWANGCOLOR_HPP

#include <string>
#include "tinytmxPropertySet.hpp"

namespace tinyxml2 {
    class XMLElement;
}

namespace tinytmx {

    class Color;

    //-------------------------------------------------------------------------
    /// A class to store the information about a color that can be used to define
    /// the corner and/or edge of a Wang tile.
    //-------------------------------------------------------------------------

    class WangColor {
    public:
        WangColor();
        ~WangColor();

        void Parse(const tinyxml2::XMLElement *wangColorElement);

        /// Get the name of this color.
        const std::string &GetName() const { return name; }

        /// Get the color.
        const Color* GetColor() const noexcept { return color; } // FIXME check all noexcept functions

        /// Get the tile ID  of the tile representing this color.
        int GetTileID() const { return tileID; }

        /// Get the relative probability that this color is chosen over others in case of multiple options.
        /// Defaults to 0;
        float GetProbability() const { return probability; }

        /// Get a set of properties re the wangcolor.
        const tinytmx::PropertySet &GetProperties() const { return properties; }

    private:
        std::string name;
        Color* color;
        int tileID;
        float probability;

        tinytmx::PropertySet properties;
    };

}
#endif //TINYTMX_TINYTMXWANGCOLOR_HPP
