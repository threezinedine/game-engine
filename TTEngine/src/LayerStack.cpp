#include "TTEngine/Layer.hpp"
#include "TTEngine/LayerStack.hpp"
#include "PrecompileHeader.hpp"
#include "TTEngine/events/Event.hpp"


namespace TTEngine {
    LayerStack::LayerStack() {
    }

    LayerStack::~LayerStack() {
        for (Layer* layer : m_layers) {
            delete layer;
        }
    }

    void LayerStack::pushOverlay(Layer* overlay) {
        m_layers.push_back(overlay);
    }

    void LayerStack::pushLayer(Layer* layer) {
        m_layers.emplace(m_layers.begin() + m_layerInsertIndex, layer);
        m_layerInsertIndex++; 
    }

    void LayerStack::popLayer(Layer* layer) {
        auto it = std::find(m_layers.begin(), m_layers.end(), layer);
        if (it != m_layers.end()) {
            m_layers.erase(it);
            m_layerInsertIndex--;
        }
    }

    void LayerStack::popOverlay(Layer* overlay) {
        auto it = std::find(m_layers.begin(), m_layers.end(), overlay);
        if (it != m_layers.end()) {
            m_layers.erase(it);
        }
    }

    void LayerStack::onUpdate() {
        for (auto layer : m_layers) {
            layer->onUpdate();
        }
    }

    void LayerStack::onEvent(Event& event) {
        for (auto it = m_layers.rbegin(); it != m_layers.rend(); ++it) {
            (*it)->onEvent(event);
            if (!event.shouldPropagateEvent()) {
                break;
            }
        }
    }
}