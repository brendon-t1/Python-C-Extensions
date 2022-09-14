#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <time.h>
#include <string.h>

char* Crps(int choice){
    // 0 is rock, 1 is paper, 2 is scissors

    // allocate space for result to be returned
    char *result = malloc(10 * sizeof(char));
    
    // generate a random number
    srand(time(0));
    int random = rand() % 3;

    // determine win, lose, draw and return the result as string
    if (random == 0){
        if (choice == 1) {
            strcpy(result, "Win");
            return result;
        }
        else if (choice == 2) {
            strcpy(result, "Lose");
            return result;
        }
        else {
            strcpy(result, "Tie");
            return result;
        }
    }
    if (random == 1){
        if (choice == 2) {
            strcpy(result, "Win");
            return result;
        }
        else if (choice == 0) {
            strcpy(result, "Lose");
            return result;
        }
        else {
            strcpy(result, "Tie");
            return result;
        }
    }
    if (random == 2){
        if (choice == 0) {
            strcpy(result, "Win");
            return result;
        }
        else if (choice == 1) {
            strcpy(result, "Lose");
            return result;
        }
        else {
            strcpy(result, "Tie");
            return result;
        }
    }
    strcpy(result, "error");
    return result;
}

static PyObject *rps(PyObject *self, PyObject *args)
{
    // put passed argument as choice to save user choice
    const int *choice;
    if (!PyArg_ParseTuple(args, "i", &choice))
        return NULL;
    
    // call Crps function and return the string result to Python
    char answer[15];
    strcpy(answer, Crps(choice));
    return PyUnicode_FromFormat(answer);
}

static PyMethodDef rpsMethods[] = {
    {"rps", rps, METH_VARARGS, "rps game"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef rpsmodule = {
    PyModuleDef_HEAD_INIT,
    "rps",
    "rps game",
    -1,
    rpsMethods
};

PyMODINIT_FUNC PyInit_rps(void) {
    return PyModule_Create(&rpsmodule);
}