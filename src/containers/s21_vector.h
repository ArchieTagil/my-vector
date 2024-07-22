#ifndef S21_VECTOR_H
#define S21_VECTOR_H

namespace s21 {
    template<typename T>
    class vector {
        public:
            typedef T value_type; // T defines the type of an element (T is template parameter)
            typedef T & reference;//	T & defines the type of the reference to an element
            typedef const T & const_reference; // defines the type of the constant reference
            typedef T * iterator; //defines the type for iterating through the container
            typedef const T * const_iterator; //const T * or internal class VectorConstIterator<T> defines the constant type for iterating through the container
            typedef size_t size_type; //size_t defines the type of the container size (standard type is size_t)

            vector(); //default constructor, creates empty vector
            explicit vector(size_type n); //parameterized constructor, creates the vector of size n
            explicit vector(std::initializer_list<value_type> const &items); //initializer list constructor, creates vector initizialized using std::initializer_list
            vector(const vector &v); //copy constructor
            vector(vector &&v); //move constructor
            ~vector(); //destructor
            vector<value_type>& operator=(vector<value_type> &&v) {
                std::cout << "\033[1;103m called assignment operator \033[0m \n";
                return v;
            };

            //getters block
            value_type *get_data() {
                return data;
            }

            size_type get_size() {
                return size;
            }

            size_type get_capacity() {
                return capacity;
            }
            //end of getters block
    
        private:
            value_type *data;
            size_type size;
            size_type capacity;
    };

    template <typename T> //default contructor
    inline vector<T>::vector(): data(nullptr), size(0), capacity(0) {
        std::cout << "\033[1;103m called default constructor \033[0m \n";  //String for deubug, need to delete
    }

    template <typename T> //constructor with size and initializated by zero
    inline vector<T>::vector(size_type n) {
        std::cout << "\033[1;103m called constructor with size \033[0m \n";  //String for deubug, need to delete
        data = new value_type[n]();
        if (data == nullptr) std::__throw_bad_alloc();
        size = n;
        capacity = n;
    }

    template <typename T> //constructor from initializer list
    inline vector<T>::vector(std::initializer_list<value_type> const &items) {
        std::cout << "\033[1;103m called constructor with initializer_list \033[0m \n"; //String for deubug, need to delete
        data = new value_type[items.size()];
        size = items.size();
        capacity = items.size();
        for (size_t i = 0; i < items.size(); i++) {
            data[i] = *(items.begin() + i);
        }
    }

    template <typename T> //copy constructor
    inline vector<T>::vector(const vector &v): size(v.size), capacity(v.capacity) {
        std::cout << "\033[1;103m called copy constructor \033[0m \n";  //String for deubug, need to delete
        this->data = new value_type[v.size];
        for (size_t i = 0; i < v.size; i++) {
            this->data[i] = v.data[i];
        }
    }

    template <typename T> //move constructor
    inline vector<T>::vector(vector &&v) {
        std::cout << "\033[1;103m called move constructor \033[0m \n";  //String for deubug, need to delete
        this->data = v.data;
        this->size = v.size;
        this->capacity = v.capacity;
        v.data = nullptr;
        v.size = 0;
        v.capacity = 0;
    }

    // template <typename T>
    // inline vector<T>& vector<T>::operator=(vector &&v) {
    //     std::cout << "\033[1;93m called assignment constructor \033[0m \n";
    // }

    template <typename T>
    inline vector<T>::~vector() {
        delete[] data;
        this->size = 0;
        this->capacity = 0;
    }
}

#endif