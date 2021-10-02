#ifndef TINYTMX_TINYTMXOBJECTGROUP_HPP
#define TINYTMX_TINYTMXOBJECTGROUP_HPP


#include <string>
#include <vector>

#include "tinytmxLayer.hpp"
#include "tinytmxPropertySet.hpp"

namespace tinyxml2 {
    class XMLNode;
}

namespace tinytmx {
    class Object;

    enum class DrawOrder {
        TMX_DRAWORDER_TOPDOWN,
        TMX_DRAWORDER_INDEX
    };

    //-------------------------------------------------------------------------
    /// The object group is in fact a map layer, and is hence called “object layer” in Tiled.
    /// A class used for holding a list of objects.
    //-------------------------------------------------------------------------
    class ObjectGroup : public tinytmx::Layer {
    public:
        /// Construct a new ObjectGroup
        explicit ObjectGroup(const tinytmx::Map *_map);

        /// Construct a new ObjectGroup used by a Tile
        ObjectGroup(const tinytmx::Tile *_tile, const tinytmx::Map *_map);

        ~ObjectGroup() override;

        /// Parse an objectgroup node.
        void Parse(const tinyxml2::XMLNode *objectGroupNode) override;

        /// Get a single object.
        const tinytmx::Object *GetObject(int index) const { return objects.at(index); }

        /// Get the number of objects in the list.
        auto GetNumObjects() const { return objects.size(); }

        /// Get the color used to display the objects in this group.
        const tinytmx::Color& GetColor() const { return color; }

        /// Get the whole list of objects.
        const std::vector<tinytmx::Object *> &GetObjects() const { return objects; }

        /// Get the draworder.
        tinytmx::DrawOrder GetDrawOrder() const { return draw_order; }

    private:
        tinytmx::Color color; // defaults to gray (“#a0a0a4”)
        std::vector<tinytmx::Object *> objects;
        DrawOrder draw_order;
    };
}

#endif //TINYTMX_TINYTMXOBJECTGROUP_HPP

