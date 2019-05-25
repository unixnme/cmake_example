#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

typedef std::vector<int> Element;

//PYBIND11_MAKE_OPAQUE(Element);
//PYBIND11_MAKE_OPAQUE(std::vector<Element>);

std::unique_ptr<std::vector<Element>> get(int i, int j) {
    auto result = std::unique_ptr<std::vector<Element>>(new std::vector<Element>());
    for (int x=0; x<i; x++) {
        Element e;
        for (int y=0; y<j; y++) e.emplace_back(y);
        result->emplace_back(e);
        }
    return result;
}
namespace py = pybind11;

PYBIND11_MODULE(cmake_example, m) {
    py::bind_vector<Element>(m, "VectorInt");
    py::bind_vector<std::vector<Element>>(m, "VectorVectorInt");
    m.def("get", &get);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
