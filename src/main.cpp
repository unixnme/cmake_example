#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

typedef std::vector<int> Element;

//PYBIND11_MAKE_OPAQUE(Element);
//PYBIND11_MAKE_OPAQUE(std::vector<Element>);

std::unique_ptr<std::vector<Element>> get(int i) {
    std::unique_ptr<std::vector<Element>> ptr(new std::vector<Element>());
    Element e;
    ptr->emplace_back(e);
    return ptr;
}

namespace py = pybind11;

PYBIND11_MODULE(cmake_example, m) {
    py::bind_vector<Element>(m, "Element");
    m.def("get", &get);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
