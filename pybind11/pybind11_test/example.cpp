#include <iostream>
#include <pybind11/pybind11.h>
#include <google/protobuf/message.h>

using namespace std;
namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

google::protobuf::Message *ttt(google::protobuf::Message &message) {
    return &message;
}

class AA {
public:
    virtual string a1() = 0;

    virtual string a2() { return "AA a2"; };
};

class BB : public AA {
public:
    virtual string b1() = 0;

    virtual string b2() { return "BB b2"; }
};

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers", py::arg("i"), py::arg("j"));

//    class PyAA : public AA {
//    public:
//        using AA::AA;
//
//        string a1() { PYBIND11_OVERLOAD_PURE(string, AA, a1,); }
//    };
    class PyBB : public BB {
    public:
        using BB::BB;

        string a1() { PYBIND11_OVERLOAD_PURE(string, BB, a1,); }

        string b1() { PYBIND11_OVERLOAD_PURE(string, BB, b1,); }
    };

//    py::class_<AA, PyAA>(m, "AA")
//            .def(py::init())
//            .def("a1", &AA::a1)
//            .def("a2", &AA::a2);

    py::class_<BB,  PyBB>(m, "BB")
            .def(py::init())
            .def("a1", &AA::a1)
            .def("a2", &AA::a2)
            .def("b1", &BB::b1)
            .def("b2", &BB::b2);



}