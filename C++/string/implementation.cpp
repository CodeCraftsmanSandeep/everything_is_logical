// implementation of string class in C++

#include <iostream>
#include <string>


namespace mySpace{
    class string{
    private:
        char* empty_string = "\0";
        char* str = empty_string;                           // empty string
        int length = 0;  
        void eraseAllocateAndReplace(const char*);                       
    public:
        string ();                                          // constructor
        string (const char* );                              // constructor with a initial string    
        string (const string& );                            // copy constructor
        string (int, char);

        ~string();

        // assignment operator
        string operator =(const string&);       
        string operator =(const char *);

        char* data() const ;                                // getter
        int size () const;                                  // get len of string
        void erase();                           

        // char* operator << (const string&);


        // addition operator
        string operator+(const string&);

        // relational operator
        bool operator<(const string&);
    };
    bool string::operator<(const string& operand){
        return strcmp(str, operand.data()) < 0;
    }
    string::string(int length, char ch){
        erase();
        this->length = length;
        str = new char[1 + length];
        for(int i = 0; i < length; i++) str[i] = ch;
        str[length] = '\0';
    }
    string string::operator+(const string& operand){
        char* buff = (char*)malloc((length + operand.size() + 1) * sizeof(char));
        snprintf(buff, length + operand.size() + 1, "%s%s", str, operand.data());
        string new_string = buff;
        return new_string;
    }
    void string::eraseAllocateAndReplace(const char* copy_str){
        erase();
        length = strlen(copy_str);
        str = new char[1 + length];
        strcpy(str, copy_str);
    }
    int string::size () const {
        return length;
    }
    char* string::data() const {
        return str;
    }
    void string::erase(){
        if(length != 0){
            delete[] str;
            str = empty_string;
            length = 0;
        }
    }
    string::string() {}
    string::string(const char* copy_str){
        erase();
        length = strlen(copy_str);
        str = new char[length + 1];
        strcpy(str, copy_str);
    }
    string::string(const string& copy_str){
        erase();
        length = copy_str.size();
        str = new char[length + 1];
        strcpy(str, copy_str.data());
    }
    string string::operator =(const string& copy_str){
        // deep copy
        eraseAllocateAndReplace(copy_str.data());
        return *this;
    }
    string string::operator =(const char* copy_str){
        // deep copy
        eraseAllocateAndReplace(copy_str);
        return *this;
    }
    string::~string(){
        erase();
    }
}

int main(){
    {
        std::string std_string = "sandeep";
        mySpace::string my_string = "sandeep";

        std::cout << std_string.data() << "\n";
        std::cout << my_string.data() << "\n";

        std_string = "programming is fun";
        my_string = "programming is fun";

        std::cout << std_string.data() << "\n";
        std::cout << my_string.data() << "\n";
    }
    std::cout << "-----------\n";
    {
        std::string std_string(5, 'e');
        mySpace::string my_string(5, 'e');

        std::cout << std_string.data() << "\n";
        std::cout << my_string.data() << "\n";

        my_string = my_string + my_string;
        std::cout << my_string.data() << "\n";
    }
    std::cout << "-----------\n";
    {
        mySpace::string myString_beg = "Hello";
        mySpace::string myString_end = "World";
        mySpace::string complete_string = myString_beg + myString_end;
        std::cout << complete_string.data() << "\n";
        std::cout << (myString_beg < myString_end) << "\n";
    }
}


