#include <vector>
#include "BigInteger/BigUnsigned.hh"
#include "BigInteger/BigIntegerUtils.hh"
#include "BigInteger/BigUnsignedInABase.hh"

int compute_checksum(BigUnsigned layout_number);
vector<int> decode_pickup_layout(string layout_string);
vector<string> layoutIntToString(vector<int> intLayout);
