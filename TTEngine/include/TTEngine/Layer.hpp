#pragma once
#include "PrecompileHeader.hpp"


namespace TTEngine {
    class Event;

    class Layer {
        public:
            Layer(const std::string& name = "Layer")
                : m_name(name) {};
            virtual ~Layer(){};

            virtual void onAttach() = 0;
            virtual void onDetach() = 0;
            virtual void onUpdate() = 0;
            virtual void onEvent(Event& event) = 0;
            std::string getName() { return m_name; }

        private:
            std::string m_name;
    };
}