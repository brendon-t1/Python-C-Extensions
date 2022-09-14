#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <time.h>
#include <string.h>

char* Crps(int choice){
    // 0 is rock, 1 is paper, 2 is scissors
    // we will return 4 for win, 5 for lose, 6 for draw

    // random is computer's choice
    //int random = 1;
    char *result = malloc(10 * sizeof(char));
    // generate random number from 1 - 3
    srand(time(0));
    int random = rand() % 3;
    // determine win, lose, draw and print result
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
    const int *choice;

    if (!PyArg_ParseTuple(args, "i", &choice))
        return NULL;
    
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