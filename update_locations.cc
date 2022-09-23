#include<string> //for stoi
#include<numeric> //for accumulate
#include<vector> // for vectors
#include<iostream> // for console
#include<time.h> // for timing
#include<stdio.h> // for file write

/////////////////
// Create a list of 'size' floating point numbers in the range [-bound, bound]
std::vector<float> generate_random_list(int size, int bound) {
    std::vector<float> vec (size);
    for (int i=0; i<size; i++) {
        vec[i] = (rand() % bound) - bound + 1; // not strict unifo but good enuf
    }
    return vec;
}

/////////////////
// Update position by velocity, one time-step
void update_coords (
    std::vector<float> &xs, std::vector<float> &ys, 
    std::vector<float> &zs, const std::vector<float> &vx,
    const std::vector<float> &vy, const std::vector<float> &vz
    ) {
    for (int i=0; i<xs.size(); i++) {
    xs[i] = xs[i] + vx[i];
    ys[i] = ys[i] + vy[i];
    zs[i] = zs[i] + vz[i]; 
    }
}

///////////////// Main:

int main (int argc, char* argv[]) {
   if (argc != 3) {
    throw std::invalid_argument("Required arguments: vector_length(N) and iterations_num(M)");
    }

    int size = std::stoi(argv[1]);
    int iters = std::stoi(argv[2]);
    srand(size);

    std::vector<float> xs = generate_random_list(size, 1000.);
    std::vector<float>ys = generate_random_list(size, 1000.);
    std::vector<float>zs = generate_random_list(size, 1000.);

    std::vector<float>vx = generate_random_list(size, 1.);
    std::vector<float>vy = generate_random_list(size, 1.);
    std::vector<float>vz = generate_random_list(size, 1.);

    struct timespec curTime;
    clock_gettime(CLOCK_MONOTONIC, &curTime);
    int time_start = curTime.tv_nsec;

    for (int i=0; i<iters; i++) {
        update_coords(xs,ys,zs,vx,vy,vz);
    }
    clock_gettime(CLOCK_MONOTONIC, &curTime);
    int time_end = curTime.tv_nsec;

    float chksum = accumulate(xs.begin(), xs.end(), 0) + 
            accumulate(ys.begin(), ys.end(),0) + accumulate(zs.begin(), zs.end(),0);

    std::cout << chksum << std::endl;
    std::cout<<time_start<< " start" << std::endl;
    std::cout << time_end << " end" << std::endl;

    float totalTime = (time_end-time_start) / double(1e3);
    float meanTime = totalTime / (float(size) * iters);

    std::cout << "Mean time: " << meanTime <<  "us" << std::endl;


    /// write to file
    FILE* fp = fopen("c_benchmark.csv", "a");
    fprintf(fp, "%f , %d \n", meanTime, size);
    fclose(fp);

return 0;
}
