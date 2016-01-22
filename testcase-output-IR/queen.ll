@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@ptr_n.line1  = common global i32 0, align 4
@ptr_ans.line2  = common global i32 0, align 4
@ptr_b.line3  = common global [ 20 x i32] zeroinitializer, align 4
@ptr_l.line4  = common global [ 40 x i32] zeroinitializer, align 4
@ptr_r.line5  = common global [ 40 x i32] zeroinitializer, align 4
define i32 @dfs( i32 %x ) #0
{
    %ptr_x.line27para = alloca i32, align 4
    store i32 %x, i32* %ptr_x.line27para, align 4
%ptr_i.line9  = alloca i32 , align 4
  %r_0.fp0 = load i32* %ptr_x.line27para, align 4
  %r_1.fp1 = load i32* @ptr_n.line1, align 4
%r_2.fp2= icmp eq i32 %r_0.fp0, %r_1.fp1
 %tmp_oneshot.fp3 = icmp ne i1 %r_2.fp2, 0
  br i1 %tmp_oneshot.fp3, label %label.if.ix1.then, label %label.if.ix1.end
 
label.if.ix1.then:
 %r_0.fp4 = load i32* @ptr_ans.line2, align 4
   %r_1.fp5 = add nsw i32 %r_0.fp4, 1
   store i32 %r_1.fp5, i32* @ptr_ans.line2, align 4
ret i32 0
br label %label.if.ix1.end
label.if.ix1.end:
  %r_2.fp7 = load i32* %ptr_i.line9, align 4
    store i32 0, i32* %ptr_i.line9, align 4
br label %label.for.ix1.check
label.for.ix1.check:
  %r_0.fp8 = load i32* %ptr_i.line9, align 4
  %r_3.fp9 = load i32* @ptr_n.line1, align 4
%r_4.fp10= icmp slt i32 %r_0.fp8, %r_3.fp9
 ; set retType to i1
  br i1 %r_4.fp10, label %label.for.ix1.body, label %label.for.ix1.end
label.for.ix1.body:
  %r_0.fp11 = load i32* %ptr_i.line9, align 4
  %r_3.fp12 = getelementptr inbounds [ 20 x i32]* @ptr_b.line3, i32 0, i32 %r_0.fp11
  %r_0.fp13 = load i32* %r_3.fp12, align 4
   %r_3.fp14 = icmp eq i32 %r_0.fp13, 0
  %r_0.fp15 = load i32* %ptr_i.line9, align 4
  %r_4.fp16 = load i32* %ptr_x.line27para, align 4
%r_5.fp17= add nsw i32 %r_0.fp15, %r_4.fp16
  %r_0.fp18 = getelementptr inbounds [ 40 x i32]* @ptr_l.line4, i32 0, i32 %r_5.fp17
  %r_4.fp19 = load i32* %r_0.fp18, align 4
   %r_0.fp20 = icmp eq i32 %r_4.fp19, 0
  %r_5.fp22 = icmp ne i1 %r_3.fp14, 0
  %r_6.fp23 = icmp ne i1 %r_0.fp20, 0
 %r_4.fp21 = and i1 %r_5.fp22, %r_6.fp23
  %r_0.fp24 = load i32* %ptr_i.line9, align 4
  %r_3.fp25 = load i32* %ptr_x.line27para, align 4
%r_5.fp26= sub nsw i32 %r_0.fp24, %r_3.fp25
  %r_0.fp27 = load i32* @ptr_n.line1, align 4
%r_3.fp28= add nsw i32 %r_5.fp26, %r_0.fp27
%r_0.fp29= sub nsw i32 %r_3.fp28, 1
  %r_3.fp30 = getelementptr inbounds [ 40 x i32]* @ptr_r.line5, i32 0, i32 %r_0.fp29
  %r_0.fp31 = load i32* %r_3.fp30, align 4
   %r_3.fp32 = icmp eq i32 %r_0.fp31, 0
  %r_5.fp34 = icmp ne i1 %r_4.fp21, 0
  %r_6.fp35 = icmp ne i1 %r_3.fp32, 0
 %r_0.fp33 = and i1 %r_5.fp34, %r_6.fp35
 %tmp_oneshot.fp36 = icmp ne i1 %r_0.fp33, 0
  br i1 %tmp_oneshot.fp36, label %label.if.ix2.then, label %label.if.ix2.end
 
label.if.ix2.then:
  %r_3.fp38 = load i32* %ptr_i.line9, align 4
  %r_4.fp39 = getelementptr inbounds [ 20 x i32]* @ptr_b.line3, i32 0, i32 %r_3.fp38
  %r_3.fp40 = load i32* %ptr_i.line9, align 4
  %r_5.fp41 = getelementptr inbounds [ 20 x i32]* @ptr_b.line3, i32 0, i32 %r_3.fp40
  %r_3.fp42 = load i32* %r_5.fp41, align 4
    store i32 1, i32* %r_4.fp39, align 4
  %r_5.fp44 = load i32* %ptr_i.line9, align 4
  %r_6.fp45 = load i32* %ptr_x.line27para, align 4
%r_7.fp46= add nsw i32 %r_5.fp44, %r_6.fp45
  %r_5.fp47 = getelementptr inbounds [ 40 x i32]* @ptr_l.line4, i32 0, i32 %r_7.fp46
  %r_6.fp48 = load i32* %ptr_i.line9, align 4
  %r_7.fp49 = load i32* %ptr_x.line27para, align 4
%r_8.fp50= add nsw i32 %r_6.fp48, %r_7.fp49
  %r_6.fp51 = getelementptr inbounds [ 40 x i32]* @ptr_l.line4, i32 0, i32 %r_8.fp50
  %r_7.fp52 = load i32* %r_6.fp51, align 4
    store i32 1, i32* %r_5.fp47, align 4
  %r_6.fp54 = load i32* %ptr_i.line9, align 4
  %r_8.fp55 = load i32* %ptr_x.line27para, align 4
%r_9.fp56= sub nsw i32 %r_6.fp54, %r_8.fp55
  %r_6.fp57 = load i32* @ptr_n.line1, align 4
%r_8.fp58= add nsw i32 %r_9.fp56, %r_6.fp57
%r_6.fp59= sub nsw i32 %r_8.fp58, 1
  %r_8.fp60 = getelementptr inbounds [ 40 x i32]* @ptr_r.line5, i32 0, i32 %r_6.fp59
  %r_6.fp61 = load i32* %ptr_i.line9, align 4
  %r_9.fp62 = load i32* %ptr_x.line27para, align 4
%r_10.fp63= sub nsw i32 %r_6.fp61, %r_9.fp62
  %r_6.fp64 = load i32* @ptr_n.line1, align 4
%r_9.fp65= add nsw i32 %r_10.fp63, %r_6.fp64
%r_10.fp66= sub nsw i32 %r_9.fp65, 1
  %r_6.fp67 = getelementptr inbounds [ 40 x i32]* @ptr_r.line5, i32 0, i32 %r_10.fp66
  %r_10.fp68 = load i32* %r_6.fp67, align 4
    store i32 1, i32* %r_8.fp60, align 4
  %r_0.fp69 = load i32* %ptr_x.line27para, align 4
%r_6.fp70= add nsw i32 %r_0.fp69, 1
%r_0.fp71 = call i32 @dfs( i32 %r_6.fp70 )
  %r_11.fp73 = load i32* %ptr_i.line9, align 4
  %r_12.fp74 = getelementptr inbounds [ 20 x i32]* @ptr_b.line3, i32 0, i32 %r_11.fp73
  %r_11.fp75 = load i32* %ptr_i.line9, align 4
  %r_13.fp76 = getelementptr inbounds [ 20 x i32]* @ptr_b.line3, i32 0, i32 %r_11.fp75
  %r_11.fp77 = load i32* %r_13.fp76, align 4
    store i32 0, i32* %r_12.fp74, align 4
  %r_9.fp79 = load i32* %ptr_i.line9, align 4
  %r_14.fp80 = load i32* %ptr_x.line27para, align 4
%r_15.fp81= add nsw i32 %r_9.fp79, %r_14.fp80
  %r_14.fp82 = getelementptr inbounds [ 40 x i32]* @ptr_l.line4, i32 0, i32 %r_15.fp81
  %r_15.fp83 = load i32* %ptr_i.line9, align 4
  %r_9.fp84 = load i32* %ptr_x.line27para, align 4
%r_16.fp85= add nsw i32 %r_15.fp83, %r_9.fp84
  %r_15.fp86 = getelementptr inbounds [ 40 x i32]* @ptr_l.line4, i32 0, i32 %r_16.fp85
  %r_16.fp87 = load i32* %r_15.fp86, align 4
    store i32 0, i32* %r_14.fp82, align 4
  %r_15.fp89 = load i32* %ptr_i.line9, align 4
  %r_9.fp90 = load i32* %ptr_x.line27para, align 4
%r_17.fp91= sub nsw i32 %r_15.fp89, %r_9.fp90
  %r_15.fp92 = load i32* @ptr_n.line1, align 4
%r_9.fp93= add nsw i32 %r_17.fp91, %r_15.fp92
%r_15.fp94= sub nsw i32 %r_9.fp93, 1
  %r_17.fp95 = getelementptr inbounds [ 40 x i32]* @ptr_r.line5, i32 0, i32 %r_15.fp94
  %r_15.fp96 = load i32* %ptr_i.line9, align 4
  %r_9.fp97 = load i32* %ptr_x.line27para, align 4
%r_18.fp98= sub nsw i32 %r_15.fp96, %r_9.fp97
  %r_15.fp99 = load i32* @ptr_n.line1, align 4
%r_9.fp100= add nsw i32 %r_18.fp98, %r_15.fp99
%r_15.fp101= sub nsw i32 %r_9.fp100, 1
  %r_18.fp102 = getelementptr inbounds [ 40 x i32]* @ptr_r.line5, i32 0, i32 %r_15.fp101
  %r_15.fp103 = load i32* %r_18.fp102, align 4
    store i32 0, i32* %r_17.fp95, align 4
br label %label.if.ix2.end
label.if.ix2.end:
br label %label.for.ix1.cond
label.for.ix1.cond:
 %r_13.fp104 = load i32* %ptr_i.line9, align 4
   %r_18.fp105 = add nsw i32 %r_13.fp104, 1
   store i32 %r_18.fp105, i32* %ptr_i.line9, align 4
  br label %label.for.ix1.check
label.for.ix1.end:
ret i32 0
}
define i32 @main() #0
{
 %tmp_oneshot.fp106 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @ptr_n.line1)
  %r_13.fp107 = load i32* @ptr_n.line1, align 4
%r_9.fp108= icmp sgt i32 %r_13.fp107, 16
 %tmp_oneshot.fp109 = icmp ne i1 %r_9.fp108, 0
  br i1 %tmp_oneshot.fp109, label %label.if.ix3.then, label %label.if.ix3.else
 
label.if.ix3.then:
   %r_13.fp110= sub nsw i32 0, 1
%tmp_oneshot.fp111 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_13.fp110)
br label %label.if.ix3.end
label.if.ix3.else:
%r_13.fp112 = call i32 @dfs( i32 0 )
  %r_9.fp113 = load i32* @ptr_ans.line2, align 4
%tmp_oneshot.fp114 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_9.fp113)
br label %label.if.ix3.end
label.if.ix3.end:
ret i32 0
}

declare i32 @__isoc99_scanf(i8*, ...) #1
declare i32 @printf(i8*, ...) #1
attributes #0 = { nounwind uwtable "less-precise-fpmad"="false""no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
