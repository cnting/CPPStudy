src = $(wildcard *.cpp)
obj = $(patsubst %cpp,%o,$(src))

test.out:$(obj)
	gcc $^ -o $@

:'
add.o:add.cpp
	gcc -c $< -o $@
sub.o:sub.cpp
	gcc -c $< -o $@
multi.o:multi.cpp
	gcc -c $< -o $@
test.o:test.cpp
	gcc -c $< -o $@
:'

#模式规则
%o:%cpp
	gcc -c $< -o $@


#先使用 make clean -n 来预执行，看下会删哪些文件。然后再用 make clean 执行真正的删除
clean:
	rm -rf $(obj) test.out
#生成伪目标
.PHONY:clean
