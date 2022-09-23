#include<string> //for stoi
#include<numeric> //for accumulate
#include<vector> // for vectors
#include<iostream> // for console
#include<time.h> // for timing
#include<stdio.h> // for file write

/////////////////
// Create a list of 'size' doubleing point numbers in the range [-bound, bound]
std::vector<double> generate_random_list(int size, int bound) {
    std::vector<double> vec (size);
    for (int i=0; i<size; i++) {
        vec[i] = (rand() % bound) - bound + 1; // not strict unifo but good enuf
    }
    return vec;
}

/////////////////
// Update position by velocity, one time-step
void update_coords (
    std::vector<double> &xs, std::vector<double> &ys, 
    std::vector<double> &zs, const std::vector<double> &vx,
    const std::vector<double> &vy, const std::vector<double> &vz
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

    std::vector<double> xs = generate_random_list(size, 1000.);
    std::vector<double>ys = generate_random_list(size, 1000.);
    std::vector<double>zs = generate_random_list(size, 1000.);

    std::vector<double>vx = generate_random_list(size, 1.);
    std::vector<double>vy = generate_random_list(size, 1.);
    std::vector<double>vz = generate_random_list(size, 1.);

    struct timespec curTime;
    clock_gettime(CLOCK_MONOTONIC, &curTime);
    int time_start = curTime.tv_nsec;

    for (int i=0; i<iters; i++) {
        update_coords(xs,ys,zs,vx,vy,vz);
    }
    clock_gettime(CLOCK_MONOTONIC, &curTime);
    int time_end = curTime.tv_nsec;

    double chksum = accumulate(xs.begin(), xs.end(), 0) + 
            accumulate(ys.begin(), ys.end(),0) + accumulate(zs.begin(), zs.end(),0);

    std::cout << chksum << std::endl;
    std::cout<<time_start<< " start" << std::endl;
    std::cout << time_end << " end" << std::endl;

    double totalTime = (time_end-time_start) / double(1e3);
    double meanTime = totalTime / (double(size) * iters);

    std::cout << "Mean time: " << meanTime <<  "us" << std::endl;


    /// write to file
    FILE* fp = fopen("typeC_benchmark.csv", "a");
    fprintf(fp, "%f , %d , double \n", meanTime, size);
    fclose(fp);

return 0;
}
