.RECIPEPREFIX = >
CFLAGS = -pedantic #-Wall -Werror -Wextra

update_locations: update_locations.cc
>   g++ $(CFLAGS) -o update_locations update_locations.cc 
