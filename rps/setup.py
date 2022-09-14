from distutils.core import setup, Extension

def main():
    setup(name="rps",
        version="1.0.0",
        description="rps with C",
        author="Brendon",
        ext_modules=[Extension("rps", ["rps_module.c"])])

if __name__=="__main__":
    main()