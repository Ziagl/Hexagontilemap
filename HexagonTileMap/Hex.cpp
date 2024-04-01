#include "Hex.h"

#ifdef PYBIND
// release mode code
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(HexagonTileMap, m)
{
    py::class_<Hex>(m, "Hex")
        .def(py::init<int, int, int>(), py::arg("q"), py::arg("r"), py::arg("s"))
        .def("q", &Hex::q)
        .def("r", &Hex::r)
        .def("s", &Hex::s)
        .def("length", &Hex::length)
        .def("distance", &Hex::distance)
        .def("neighbor", &Hex::neighbor)
        .def("__eq__", &Hex::operator==)
        .def("__ne__", &Hex::operator!=)
        .def("__add__", &Hex::operator+)
        .def("__sub__", &Hex::operator-)
        .def("__mul__", &Hex::operator*, py::arg("k"));
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
#endif