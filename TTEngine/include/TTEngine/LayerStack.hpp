#pragma once
#include "PrecompileHeader.hpp"
#include "Layer.hpp"


namespace TTEngine {
    class Event;
    class Layer;

    class LayerStack {
        public:
            LayerStack();
            ~LayerStack();

            void pushLayer(Layer* layer);
            void pushOverlay(Layer* overlay);

            void popLayer(Layer* layer);
            void popOverlay(Layer* overlay);

            void onUpdate();
            void onEvent(Event& event);

        private:
            std::vector<Layer*> m_layers;
            int m_layerInsertIndex = 0;
    };
}