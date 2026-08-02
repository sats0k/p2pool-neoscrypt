#include <Python.h>

#include "neoscrypt.h"

static PyObject *neoscrypt_getpowhash(PyObject *self, PyObject *args)
{
    const unsigned char *input;
    Py_ssize_t input_len;
    unsigned char output[32];

    if (!PyArg_ParseTuple(args, "y#", &input, &input_len))
        return NULL;

    /* NeoScrypt hashes an 80-byte block header */
    neoscrypt((unsigned char *)input, output);

    return PyBytes_FromStringAndSize((const char *)output, 32);
}

static PyMethodDef NeoScryptMethods[] = {
    {
        "getPoWHash",
        neoscrypt_getpowhash,
        METH_VARARGS,
        "Returns proof-of-work hash using NeoScrypt"
    },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef neoscryptmodule = {
    PyModuleDef_HEAD_INIT,
    "neoscrypt",
    "NeoScrypt module",
    -1,
    NeoScryptMethods
};

PyMODINIT_FUNC PyInit_neoscrypt(void)
{
    return PyModule_Create(&neoscryptmodule);
}