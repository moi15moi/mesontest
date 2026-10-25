#include <nanobind/nanobind.h>

int add(int x, int y) {
    return x + y;
}

NB_MODULE(my_module, m) {

    m.def("add", &add, nanobind::arg("x"), nanobind::arg("y"));
}
