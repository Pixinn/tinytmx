#ifndef TINYTMX_TINYTMXLAYER_HPP
#define TINYTMX_TINYTMXLAYER_HPP


#include <string>
#include "tinytmxPropertySet.hpp"

namespace tinyxml2 {
    class XMLNode;
}

namespace tinytmx {
    class Map;

    class Tile;

    enum class LayerType {
        TMX_LAYERTYPE_TILE = 0X01,
        TMX_LAYERTYPE_OBJECTGROUP = 0X02,
        TMX_LAYERTYPE_IMAGE_LAYER = 0X04,
        TMX_LAYERTYPE_GROUP_LAYER = 0X08
    };

    //-------------------------------------------------------------------------
    /// Base class for other layer types.
    //-------------------------------------------------------------------------
    class Layer {
    private:

    public:

        // Delete copy constructor.
        Layer(const Layer &) = delete;

        // Delete assignment constructor.
        Layer &operator=(const Layer &) = delete;

        /// Construct a new Layer used by a map's objectgroup
        Layer(const tinytmx::Map *_map, std::string _name, int _x, int _y,
              uint32_t _width, uint32_t _height, float _opacity, bool _visible,
              LayerType _layerType);

        /// Construct a new layer used by a tile's objectgroup
        Layer(const tinytmx::Tile *_tile,
              const tinytmx::Map *_map,
              std::string _name, int _x, int _y,
              uint32_t _width, uint32_t _height, float _opacity, bool _visible,
              LayerType _layerType);

        virtual ~Layer() = default;

        /// Parse a layer element.
        virtual void Parse(const tinyxml2::XMLNode *layerNode) = 0;

        /// Get the pointer to the parent map.
        const tinytmx::Map *mapGetMap() const { return map; }

        /// Get the name of the layer.
        const std::string &GetName() const { return name; }

        /// Get the ID.
        uint32_t GetID() const { return ID; }

        /// Get the value of the x attribute of the layer. Means different things for different layer types.
        int GetX() const { return x; }

        /// Get the value of the y attribute of the layer. Means different things for different layer types.
        int GetY() const { return y; }

        /// Get the width of the layer, in tiles. Only used in tile layers.
        uint32_t GetWidth() const { return width; }

        /// Get the height of the layer, in tiles. Only used in tile layers.
        uint32_t GetHeight() const { return height; }

        /// Get the opacity of the layer.
        float GetOpacity() const { return opacity; }

        /// Get the visibility of the layer
        bool IsVisible() const { return visible; }

        /// Get the tint color.
        const tinytmx::Color& GetTintColor() const { return tint_color; }

        // FIXME should probably be deprecated.
//        /// Sets the offset for this GroupLayer
//        void SetOffset(float offsetXv, float offsetYv) {
//            offsetX = offsetXv;
//            offsetY = offsetYv;
//        }

        /// Returns the x offset.
        float GetOffsetX() const noexcept { return offsetX; }

        /// Returns the y offset.
        float GetOffsetY() const noexcept { return offsetY; }

        /// Get the property set.
        const tinytmx::PropertySet &GetProperties() const { return properties; }

        /// Get the zorder of the layer.
        int GetZOrder() const { return zOrder; }

        /// Set the zorder of the layer.
        //void SetZOrder(int z) { zOrder = z; }
        int& SetZOrder() { return zOrder; }

        /// Get the parse order of the layer.
        int GetParseOrder() const { return parseOrder; }

        /// Get the type of the layer.
        tinytmx::LayerType GetLayerType() const { return layerType; }


    protected:
        /// @cond INTERNAL
        const tinytmx::Map *map;
        const tinytmx::Tile *tile;
        std::string name;

        uint32_t ID;

        int x;
        int y;
        uint32_t width;
        uint32_t height;

        float opacity;
        bool visible;

        tinytmx::Color tint_color;

        float offsetX;
        float offsetY;

        int zOrder;
        const int parseOrder;

        const tinytmx::LayerType layerType;

        tinytmx::PropertySet properties;

        static int nextParseOrder;
        /// @endcond
    };
}

#endif //TINYTMX_TINYTMXLAYER_HPP
