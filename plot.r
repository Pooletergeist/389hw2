ggplot(data=data1, aes(x=size, y=time)) + geom_line(color="blue") + geom_point() + xlab("number of objects") + ylab("mean time to update (us)") + labs(title="Python Masstronauts Update Benchmark. Mean time for coordinate update vs. number of objects") + guides(color = guide_none()) 

ggplot(data=data, aes(x=size, y=time)) + geom_line(aes(color=language)) + geom_point() + xlab("number of objects") + ylab("mean time to update (us)") + labs(title="Masstronauts Update Benchmark. Mean time for coordinate update vs. number of objects")



