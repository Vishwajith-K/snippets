import ctypes
import sys

lib = './bitwisepy_%s.so' % (sys.platform)
bitwise_lib = ctypes.CDLL(lib)

bit_lsh_i = bitwise_lib.bit_lsh_i
bit_lsh_i.restype = ctypes.c_int

print(bit_lsh_i(5, 2))
