#include <Python.h>

// The C function we want to expose
static PyObject* py_add(PyObject* self, PyObject* args, PyObject* kwargs) {
    static char* kwlist[] = {"x", "y", NULL};
    int x, y;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ii", kwlist, &x, &y)) {
        return NULL;  // Error parsing arguments
    }

    int result = x + y;
    return PyLong_FromLong(result);
}

// Method definition table
static PyMethodDef MyModuleMethods[] = {
    {"add", (PyCFunction)py_add, METH_VARARGS | METH_KEYWORDS, "Add two integers"},
    {NULL, NULL, 0, NULL}  // Sentinel
};

// Module definition
static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT,
    "my_module",   // Module name
    "Example module using Python C API",  // Module doc
    -1,            // Size of per-interpreter state of the module
    MyModuleMethods
};

// Module initialization function
PyMODINIT_FUNC PyInit_my_module(void) {
    return PyModule_Create(&mymodule);
}
