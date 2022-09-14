#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *return_string(PyObject *self, PyObject *args)
{
    const int *passed;

    if (!PyArg_ParseTuple(args, "i", &passed))
        return NULL;
    
    const char answer[15] = "It Worked";
    return PyUnicode_FromFormat(answer);
}

static PyMethodDef returnStringMethods[] = {
    {"return_string", return_string, METH_VARARGS, "return string test"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef returnStringmodule = {
    PyModuleDef_HEAD_INIT,
    "return_string",
    "return string test",
    -1,
    returnStringMethods
};

PyMODINIT_FUNC PyInit_return_string(void) {
    return PyModule_Create(&returnStringmodule);
}