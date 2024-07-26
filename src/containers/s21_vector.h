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
            vector<value_type>& operator=(vector<value_type> &&v);

            //getters block
            value_type *get_data() {
                return data_;
            }

            size_type get_size() {
                return size_;
            }

            size_type get_capacity() {
                return capacity_;
            }
            //end of getters block

            //table capacity
            bool empty();
            size_type size();
            size_type max_size();
            size_type capacity();
            void reserve(size_type size);
            void shrink_to_fit();
            //end table capacity

            //table Element access
            reference at(size_type pos);
            reference operator[](size_type pos);
            const_reference front();
            const_reference back();
            T* data();
            //end table Element access

            //table Modifiers
            void clear();
            iterator insert(iterator pos, const_reference value);
            void erase(iterator pos);
            void push_back(const_reference value);
            void pop_back();
            void swap(vector& other);
            //end of table modifiers
            
            //table iterators
            iterator begin();
            iterator end();
            //end table iterators
    
        private:
            value_type *data_;
            size_type size_;
            size_type capacity_;
    };

    template <typename T> //default contructor
    inline vector<T>::vector(): data_(nullptr), size_(0), capacity_(0) {}

    template <typename T> //constructor with size and initializated by zero
    inline vector<T>::vector(size_type n) {
        data_ = new value_type[n]();
        if (data_ == nullptr) std::__throw_bad_alloc();
        size_ = n;
        capacity_ = n;
    }

    template <typename T> //constructor from initializer list
    inline vector<T>::vector(std::initializer_list<value_type> const &items) {
        data_ = new value_type[items.size()];
        size_ = items.size();
        capacity_ = items.size();
        for (size_t i = 0; i < items.size(); i++) {
            data_[i] = *(items.begin() + i);
        }
    }

    template <typename T> //copy constructor
    inline vector<T>::vector(const vector &v): size_(v.size_), capacity_(v.capacity_) {
        this->data_ = new value_type[v.size_];
        for (size_t i = 0; i < v.size_; i++) {
            this->data_[i] = v.data_[i];
        }
    }

    template <typename T> //move constructor
    inline vector<T>::vector(vector &&v) {
        this->data_ = v.data_;
        this->size_ = v.size_;
        this->capacity_ = v.capacity_;
        v.data_ = nullptr;
        v.size_ = 0;
        v.capacity_ = 0;
    }

    template <typename T>
    inline vector<T>& vector<T>::operator=(vector &&v) {
        data_ = v.data_;
        capacity_ = v.capacity_;
        size_ = v.size_;
        v.data_ = nullptr;
        v.capacity_ = 0;
        v.size_ = 0;
        return *this;
    }

    template <typename T>
    inline vector<T>::~vector() {
        delete[] data_;
        this->size_ = 0;
        this->capacity_ = 0;
    }

    template <typename T>
    inline bool vector<T>::empty() {
        return this->size_ == 0;
    }

    template <typename T>
    inline typename vector<T>::size_type vector<T>::size() {
        return this->size_;
    }

    template <typename T>
    inline typename vector<T>::size_type vector<T>::max_size() {
        return SIZE_MAX / sizeof(T) / 2;;
    }

    template <typename T>
    inline typename vector<T>::size_type vector<T>::capacity() {
        return this->capacity_;
    }

    template <typename T>
    inline void vector<T>::reserve(size_type size) {
        if (this->capacity_ < size) {
            T *tmp_data = new T[size]();
            for (size_type i = 0; i < size_; i++) {
                tmp_data[i] = this->data_[i];
            }
            capacity_ = size;
            delete[] this->data_;
            this->data_ = tmp_data;
        }
    }

    template <typename T>
    inline void vector<T>::shrink_to_fit() {
        if (this->capacity_ > this->size_) {
            T *tmp_data = new T[this->size_]();
            for (size_t i = 0; i < this->size_; i++) {
                tmp_data[i] = this->data_[i];
            }
            delete[] this->data_;
            this->data_ = tmp_data;
            this->capacity_ = this->size_;
        }
    }

    template <typename T>
    inline typename vector<T>::reference vector<T>::at(size_type pos) {
        if (pos < this->size_) {
            return *(this->data_ + pos);
        } else {
            throw std::out_of_range("index out of bounds");
        }
    }

    template <typename T>
    inline typename vector<T>::reference vector<T>::operator[](size_type pos) {
        return *(this->data_ + pos);
    }

    template <typename T>
    inline typename vector<T>::const_reference vector<T>::front() {
        return *(this->data_);
    }

    template <typename T>
    inline typename vector<T>::const_reference vector<T>::back() {
        return *(this->data_ + this->size_ - 1);
    }

    template <typename T>
    T* vector<T>::data() {
        return this->data_;
    }

    template <typename T>
    inline void vector<T>::clear() {
        this->size_ = 0;
    }

    template <typename T>
    inline typename vector<T>::iterator vector<T>::insert(iterator pos, const_reference value) {
        int pos_index = pos - this->begin();
        if (pos - this->begin() < 0 || this->end() - pos < 0) {
            throw std::out_of_range("iterator index is out of bounds");
        } else {
            if (capacity_ <= size_) {
                this->reserve(size_ * 2);
            }
            for (int i = size_; i >= 0; i--) {
                if (i >= pos_index) this->data_[i + 1] = this->data_[i];
            }
            size_++;
        }
        this->data_[pos_index] = value;
        return &this->data_[pos_index];
    }

    template <typename T>
    inline void vector<T>::erase(iterator pos) {
        if (pos - this->begin() < 0 || this->end() - pos - 1 < 0) {
            throw std::out_of_range("iterator index is out of bounds");
        } else {
            while (pos < this->end() - 1) {
                *pos = *(pos + 1);
                pos++;
            }
            this->size_ -= 1;
        }
    }

    template <typename T>
    inline void vector<T>::push_back(const_reference value) {
        this->insert(this->end(), value);
    }

    template <typename T>
    inline void vector<T>::pop_back() {
        this->erase(this->end() - 1);
    }

    template <typename T>
    inline void vector<T>::swap(vector& other) {
        T *tmp_data = this->data_;
        size_type tmp_size = this->size_;
        size_type tmp_capacity = this->capacity_; 

        this->data_ = other.data_;
        this->size_ = other.size_;
        this->capacity_ = other.capacity_;

        other.data_ = tmp_data;
        other.size_ = tmp_size;
        other.capacity_ = tmp_capacity;
    }

    template <typename T>
    inline typename vector<T>::iterator vector<T>::begin() {
        return this->data_;
    }

    template <typename T>
    inline typename vector<T>::iterator vector<T>::end() {
        return this->data_ + this->size_;
    }
}

#endif