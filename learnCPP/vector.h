    class Vector {
    private:
        int sz;
        double* elements;
    public:
        Vector(int sz);
        double& operator[](int pos);
        int size();
        ~Vector();
    };
