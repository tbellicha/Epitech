/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07am-tanguy.bellicha
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor {
        public:
            QuantumReactor();
            bool isStable();
            void setStability(bool stability);

        protected:
        private:
            bool _stability;
    };

    class Core {
        public:
            Core(QuantumReactor *QR);
            QuantumReactor *checkReactor();

        protected:
        private:
            QuantumReactor *_coreReactor;
    };
}

#endif /* !WARPSYSTEM_HPP_ */
