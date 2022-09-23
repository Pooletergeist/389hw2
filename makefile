.RECIPEPREFIX = >
CFLAGS = -pedantic #-Wall -Werror -Wextra

update_locations: update_locations.cc
>   g++ $(CFLAGS) -o update_locations update_locations.cc 

double: double_update_locations.cc
>   g++ $(CFLAGS) -o doubleBench double_update_locations.cc 

int8: int8_update_locations.cc
>   g++ $(CFLAGS) -o int8Bench int8_update_locations.cc 

int16: int16_update_locations.cc
>   g++ $(CFLAGS) -o int16Bench int16_update_locations.cc 

int32: int32_update_locations.cc
>   g++ $(CFLAGS) -o int32Bench int32_update_locations.cc 

int64: int64_update_locations.cc
>   g++ $(CFLAGS) -o int64Bench int64_update_locations.cc 

float: float_update_locations.cc
>   g++ $(CFLAGS) -o floatBench float_update_locations.cc


