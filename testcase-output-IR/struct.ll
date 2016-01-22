 %acrossthegreatxxxxwallwecanreacheverycornerintheworld = type {i32 }
 %haoehaoehaoewozhendehaoe = type {i32 ,i32 ,i32 ,i32 }
 %doubleO = type {i32 ,i32 ,i32 ,i32 ,i32 }
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@ptr_A.line19.struct = common global %acrossthegreatxxxxwallwecanreacheverycornerintheworld zeroinitializer, align 4
@ptr_B.line19.struct = common global %acrossthegreatxxxxwallwecanreacheverycornerintheworld zeroinitializer, align 4
@ptr_C.line20.struct = common global %haoehaoehaoewozhendehaoe zeroinitializer, align 4
@ptr_R.line21.struct = common global %doubleO zeroinitializer, align 4
@ptr_G.line21.struct = common global %doubleO zeroinitializer, align 4
@ptr_T.line21.struct = common global %doubleO zeroinitializer, align 4
define i32 @main() #0
{
%r_0.fp0 = getelementptr inbounds %doubleO* @ptr_T.line21.struct, i32 0, i32 0
 %tmp_oneshot.fp1 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %r_0.fp0)
%r_0.fp2 = getelementptr inbounds %acrossthegreatxxxxwallwecanreacheverycornerintheworld* @ptr_A.line19.struct, i32 0, i32 0
 %tmp_oneshot.fp3 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %r_0.fp2)
%r_0.fp4 = getelementptr inbounds %haoehaoehaoewozhendehaoe* @ptr_C.line20.struct, i32 0, i32 1
 %tmp_oneshot.fp5 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %r_0.fp4)
%r_1.fp7 = getelementptr inbounds %doubleO* @ptr_G.line21.struct, i32 0, i32 1
%r_2.fp8 = getelementptr inbounds %doubleO* @ptr_G.line21.struct, i32 0, i32 1
  %r_3.fp9 = load i32* %r_2.fp8, align 4
%r_2.fp10 = getelementptr inbounds %doubleO* @ptr_T.line21.struct, i32 0, i32 0
  %r_4.fp11 = load i32* %r_2.fp10, align 4
%r_2.fp12 = getelementptr inbounds %haoehaoehaoewozhendehaoe* @ptr_C.line20.struct, i32 0, i32 1
  %r_5.fp13 = load i32* %r_2.fp12, align 4
%r_2.fp14= xor i32 %r_4.fp11, %r_5.fp13
    store i32 %r_2.fp14, i32* %r_1.fp7, align 4
%r_0.fp15 = getelementptr inbounds %doubleO* @ptr_G.line21.struct, i32 0, i32 1
  %r_2.fp16 = load i32* %r_0.fp15, align 4
%r_0.fp17 = getelementptr inbounds %acrossthegreatxxxxwallwecanreacheverycornerintheworld* @ptr_A.line19.struct, i32 0, i32 0
  %r_4.fp18 = load i32* %r_0.fp17, align 4
%r_0.fp19= icmp eq i32 %r_2.fp16, %r_4.fp18
 %tmp_oneshot.fp20 = icmp ne i1 %r_0.fp19, 0
  br i1 %tmp_oneshot.fp20, label %label.if.ix1.then, label %label.if.ix1.else
 
label.if.ix1.then:
%r_2.fp22 = getelementptr inbounds %haoehaoehaoewozhendehaoe* @ptr_C.line20.struct, i32 0, i32 0
%r_4.fp23 = getelementptr inbounds %haoehaoehaoewozhendehaoe* @ptr_C.line20.struct, i32 0, i32 0
  %r_5.fp24 = load i32* %r_4.fp23, align 4
    store i32 215, i32* %r_2.fp22, align 4
br label %label.if.ix1.end
label.if.ix1.else:
%r_4.fp26 = getelementptr inbounds %haoehaoehaoewozhendehaoe* @ptr_C.line20.struct, i32 0, i32 0
%r_6.fp27 = getelementptr inbounds %haoehaoehaoewozhendehaoe* @ptr_C.line20.struct, i32 0, i32 0
  %r_7.fp28 = load i32* %r_6.fp27, align 4
    store i32 0, i32* %r_4.fp26, align 4
br label %label.if.ix1.end
label.if.ix1.end:
%r_0.fp29 = getelementptr inbounds %haoehaoehaoewozhendehaoe* @ptr_C.line20.struct, i32 0, i32 0
  %r_6.fp30 = load i32* %r_0.fp29, align 4
%tmp_oneshot.fp31 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_6.fp30)
%r_0.fp32 = getelementptr inbounds %doubleO* @ptr_R.line21.struct, i32 0, i32 2
 %tmp_oneshot.fp33 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %r_0.fp32)
%r_0.fp34 = getelementptr inbounds %doubleO* @ptr_R.line21.struct, i32 0, i32 2
  %r_6.fp35 = load i32* %r_0.fp34, align 4
 %tmp_oneshot.fp36 = icmp ne i32 %r_6.fp35, 0
  br i1 %tmp_oneshot.fp36, label %label.if.ix2.then, label %label.if.ix2.else
 
label.if.ix2.then:
%tmp_oneshot.fp37 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 215)
br label %label.if.ix2.end
label.if.ix2.else:
   %r_0.fp38= sub nsw i32 0, 215
%tmp_oneshot.fp39 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_0.fp38)
br label %label.if.ix2.end
label.if.ix2.end:
ret i32 0
}

declare i32 @__isoc99_scanf(i8*, ...) #1
declare i32 @printf(i8*, ...) #1
attributes #0 = { nounwind uwtable "less-precise-fpmad"="false""no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
