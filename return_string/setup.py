from distutils.core import setup, Extension

def main():
    setup(name="return_string",
        version="1.0.0",
        description="return string with C",
        author="Brendon",
        ext_modules=[Extension("return_string", ["string_module.c"])])

if __name__=="__main__":
    main()