/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD12-tanguy.bellicha
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
#define UNIQUEPOINTER_HPP_

template <typename T>
class UniquePointer {
    public:
        UniquePointer(T *ptr) {
            this->ptr = ptr;
        }

        UniquePointer() {
            this->ptr = nullptr;
        }

        ~UniquePointer() {
            delete this->ptr;
        }

        void reset() {
            delete this->ptr;
            this->ptr = nullptr;
        }

        T* get() const {
            return (this->ptr);
        }

        T* operator->() const {
            return (this->ptr);
        }

        UniquePointer(const UniquePointer&) {}
        UniquePointer& operator=(const UniquePointer&) {
            return (*this);
        }

    protected:
    private:
        T *ptr;
};

#endif /* !UNIQUEPOINTER_HPP_ */
