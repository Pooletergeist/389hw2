## makes some plots

data <- read.csv("typeC_benchmark.csv")

require(ggplot2)
require(dplyr)

data <- filter(data, time>0) # clock monotonic resets can mess up timing

p <- ggplot(data=data, aes(x=size, y=time)) +
    geom_line(aes(color=type)) +
    geom_point(aes(color=type)) +
    xlab("number of objects") +
    ylab("mean time to update coordinates (microseconds)") +
    labs(title="Masstronauts Benchmark. mean time to update vs. numObjects for C numeric types")

print(p)
