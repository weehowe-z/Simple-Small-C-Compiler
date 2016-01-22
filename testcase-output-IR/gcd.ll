@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@ptr_a.line1  = common global i32 0, align 4
@ptr_b.line1  = common global i32 0, align 4
define i32 @gcd( i32 %x , i32 %y ) #0
{
    %ptr_x.line8para = alloca i32, align 4
    store i32 %x, i32* %ptr_x.line8para, align 4
    %ptr_y.line8para = alloca i32, align 4
    store i32 %y, i32* %ptr_y.line8para, align 4
  %r_0.fp0 = load i32* %ptr_y.line8para, align 4
   %r_1.fp1 = icmp eq i32 %r_0.fp0, 0
 %tmp_oneshot.fp2 = icmp ne i1 %r_1.fp1, 0
  br i1 %tmp_oneshot.fp2, label %label.if.ix1.then, label %label.if.ix1.end
 
label.if.ix1.then:
  %r_0.fp3 = load i32* %ptr_x.line8para, align 4
ret i32 %r_0.fp3
br label %label.if.ix1.end
label.if.ix1.end:
  %r_0.fp4 = load i32* %ptr_y.line8para, align 4
  %r_1.fp5 = load i32* %ptr_x.line8para, align 4
  %r_2.fp6 = load i32* %ptr_y.line8para, align 4
%r_3.fp7= srem i32 %r_1.fp5, %r_2.fp6
%r_1.fp8 = call i32 @gcd( i32 %r_0.fp4 , i32 %r_3.fp7 )
ret i32 %r_1.fp8
}
define i32 @main() #0
{
 %tmp_oneshot.fp9 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @ptr_a.line1)
 %tmp_oneshot.fp10 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @ptr_b.line1)
  %r_1.fp11 = load i32* @ptr_a.line1, align 4
  %r_2.fp12 = load i32* @ptr_b.line1, align 4
%r_4.fp13 = call i32 @gcd( i32 %r_1.fp11 , i32 %r_2.fp12 )
%tmp_oneshot.fp14 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_4.fp13)
ret i32 0
}

declare i32 @__isoc99_scanf(i8*, ...) #1
declare i32 @printf(i8*, ...) #1
attributes #0 = { nounwind uwtable "less-precise-fpmad"="false""no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
