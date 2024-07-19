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
            vector(size_type n); //parameterized constructor, creates the vector of size n
            vector(std::initializer_list<value_type> const &items); //initializer list constructor, creates vector initizialized using std::initializer_list
            vector(const vector &v); //copy constructor
            vector(vector &&v); //move constructor
            ~vector(); //destructor
            // operator=(vector &&v); //assignment operator overload for moving object
    
        private:
            value_type *data;
            size_type size;
            size_type capacity;
    };
}