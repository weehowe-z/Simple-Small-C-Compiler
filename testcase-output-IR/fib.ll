@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@ptr_mat.line1  = common global [ 4 x i32] [  i32 0 , i32 1 , i32 1 , i32 1  ], align 4
@ptr_n.line2  = common global i32 0, align 4
@ptr_MOD.line3  = common global i32 10007, align 4
define i32 @solve( i32 %x ) #0
{
    %ptr_x.line28para = alloca i32, align 4
    store i32 %x, i32* %ptr_x.line28para, align 4
%ptr_p.line7  = alloca i32 , align 4
%ptr_q.line7  = alloca i32 , align 4
%ptr_r.line7  = alloca i32 , align 4
%ptr_s.line7  = alloca i32 , align 4
%ptr_ans.line8  = alloca [ 2 x i32] , align 4
%tmp_oneshot.fp0 =  getelementptr inbounds [2 x i32]* %ptr_ans.line8, i32 0, i32 0
  store i32 0, i32* %tmp_oneshot.fp0, align 4
%tmp_oneshot.fp1 =  getelementptr inbounds [2 x i32]* %ptr_ans.line8, i32 0, i32 1
  store i32 1, i32* %tmp_oneshot.fp1, align 4
br label %label.for.ix1.check
label.for.ix1.check:
  %r_0.fp2 = load i32* %ptr_x.line28para, align 4
 %tmp_oneshot.fp3 = icmp ne i32 %r_0.fp2, 0 
; for conversion
  br i1 %tmp_oneshot.fp3, label %label.for.ix1.body, label %label.for.ix1.end
label.for.ix1.body:
  %r_0.fp4 = load i32* %ptr_x.line28para, align 4
%r_1.fp5= and i32 %r_0.fp4, 1
 %tmp_oneshot.fp6 = icmp ne i32 %r_1.fp5, 0
  br i1 %tmp_oneshot.fp6, label %label.if.ix1.then, label %label.if.ix1.end
 
label.if.ix1.then:
  %r_1.fp8 = load i32* %ptr_p.line7, align 4
  %r_2.fp9 = getelementptr inbounds [ 2 x i32]* %ptr_ans.line8, i32 0, i32 0
  %r_3.fp10 = load i32* %r_2.fp9, align 4
  %r_2.fp11 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 0
  %r_4.fp12 = load i32* %r_2.fp11, align 4
%r_2.fp13= mul nsw i32 %r_3.fp10, %r_4.fp12
  %r_3.fp14 = getelementptr inbounds [ 2 x i32]* %ptr_ans.line8, i32 0, i32 1
  %r_4.fp15 = load i32* %r_3.fp14, align 4
  %r_3.fp16 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 2
  %r_5.fp17 = load i32* %r_3.fp16, align 4
%r_3.fp18= mul nsw i32 %r_4.fp15, %r_5.fp17
%r_4.fp19= add nsw i32 %r_2.fp13, %r_3.fp18
    store i32 %r_4.fp19, i32* %ptr_p.line7, align 4
  %r_2.fp21 = load i32* %ptr_q.line7, align 4
  %r_3.fp22 = getelementptr inbounds [ 2 x i32]* %ptr_ans.line8, i32 0, i32 0
  %r_5.fp23 = load i32* %r_3.fp22, align 4
  %r_3.fp24 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 1
  %r_6.fp25 = load i32* %r_3.fp24, align 4
%r_3.fp26= mul nsw i32 %r_5.fp23, %r_6.fp25
  %r_5.fp27 = getelementptr inbounds [ 2 x i32]* %ptr_ans.line8, i32 0, i32 1
  %r_6.fp28 = load i32* %r_5.fp27, align 4
  %r_5.fp29 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 3
  %r_7.fp30 = load i32* %r_5.fp29, align 4
%r_5.fp31= mul nsw i32 %r_6.fp28, %r_7.fp30
%r_6.fp32= add nsw i32 %r_3.fp26, %r_5.fp31
    store i32 %r_6.fp32, i32* %ptr_q.line7, align 4
  %r_3.fp34 = getelementptr inbounds [ 2 x i32]* %ptr_ans.line8, i32 0, i32 0
  %r_5.fp35 = getelementptr inbounds [ 2 x i32]* %ptr_ans.line8, i32 0, i32 0
  %r_7.fp36 = load i32* %r_5.fp35, align 4
  %r_5.fp37 = load i32* %ptr_p.line7, align 4
  %r_8.fp38 = load i32* @ptr_MOD.line3, align 4
%r_9.fp39= srem i32 %r_5.fp37, %r_8.fp38
    store i32 %r_9.fp39, i32* %r_3.fp34, align 4
  %r_5.fp41 = getelementptr inbounds [ 2 x i32]* %ptr_ans.line8, i32 0, i32 1
  %r_8.fp42 = getelementptr inbounds [ 2 x i32]* %ptr_ans.line8, i32 0, i32 1
  %r_10.fp43 = load i32* %r_8.fp42, align 4
  %r_8.fp44 = load i32* %ptr_q.line7, align 4
  %r_11.fp45 = load i32* @ptr_MOD.line3, align 4
%r_12.fp46= srem i32 %r_8.fp44, %r_11.fp45
    store i32 %r_12.fp46, i32* %r_5.fp41, align 4
br label %label.if.ix1.end
label.if.ix1.end:
  %r_11.fp48 = load i32* %ptr_p.line7, align 4
  %r_8.fp49 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 0
  %r_13.fp50 = load i32* %r_8.fp49, align 4
  %r_8.fp51 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 0
  %r_14.fp52 = load i32* %r_8.fp51, align 4
%r_8.fp53= mul nsw i32 %r_13.fp50, %r_14.fp52
  %r_13.fp54 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 1
  %r_14.fp55 = load i32* %r_13.fp54, align 4
  %r_13.fp56 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 2
  %r_15.fp57 = load i32* %r_13.fp56, align 4
%r_13.fp58= mul nsw i32 %r_14.fp55, %r_15.fp57
%r_14.fp59= add nsw i32 %r_8.fp53, %r_13.fp58
    store i32 %r_14.fp59, i32* %ptr_p.line7, align 4
  %r_13.fp61 = load i32* %ptr_q.line7, align 4
  %r_15.fp62 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 0
  %r_8.fp63 = load i32* %r_15.fp62, align 4
  %r_15.fp64 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 1
  %r_16.fp65 = load i32* %r_15.fp64, align 4
%r_15.fp66= mul nsw i32 %r_8.fp63, %r_16.fp65
  %r_16.fp67 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 1
  %r_8.fp68 = load i32* %r_16.fp67, align 4
  %r_16.fp69 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 3
  %r_17.fp70 = load i32* %r_16.fp69, align 4
%r_16.fp71= mul nsw i32 %r_8.fp68, %r_17.fp70
%r_17.fp72= add nsw i32 %r_15.fp66, %r_16.fp71
    store i32 %r_17.fp72, i32* %ptr_q.line7, align 4
  %r_15.fp74 = load i32* %ptr_r.line7, align 4
  %r_16.fp75 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 2
  %r_8.fp76 = load i32* %r_16.fp75, align 4
  %r_16.fp77 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 0
  %r_18.fp78 = load i32* %r_16.fp77, align 4
%r_16.fp79= mul nsw i32 %r_8.fp76, %r_18.fp78
  %r_18.fp80 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 3
  %r_8.fp81 = load i32* %r_18.fp80, align 4
  %r_18.fp82 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 2
  %r_19.fp83 = load i32* %r_18.fp82, align 4
%r_18.fp84= mul nsw i32 %r_8.fp81, %r_19.fp83
%r_19.fp85= add nsw i32 %r_16.fp79, %r_18.fp84
    store i32 %r_19.fp85, i32* %ptr_r.line7, align 4
  %r_16.fp87 = load i32* %ptr_s.line7, align 4
  %r_18.fp88 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 1
  %r_8.fp89 = load i32* %r_18.fp88, align 4
  %r_18.fp90 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 2
  %r_20.fp91 = load i32* %r_18.fp90, align 4
%r_18.fp92= mul nsw i32 %r_8.fp89, %r_20.fp91
  %r_20.fp93 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 3
  %r_8.fp94 = load i32* %r_20.fp93, align 4
  %r_20.fp95 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 3
  %r_21.fp96 = load i32* %r_20.fp95, align 4
%r_20.fp97= mul nsw i32 %r_8.fp94, %r_21.fp96
%r_21.fp98= add nsw i32 %r_18.fp92, %r_20.fp97
    store i32 %r_21.fp98, i32* %ptr_s.line7, align 4
  %r_18.fp100 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 0
  %r_20.fp101 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 0
  %r_8.fp102 = load i32* %r_20.fp101, align 4
  %r_20.fp103 = load i32* %ptr_p.line7, align 4
  %r_22.fp104 = load i32* @ptr_MOD.line3, align 4
%r_23.fp105= srem i32 %r_20.fp103, %r_22.fp104
    store i32 %r_23.fp105, i32* %r_18.fp100, align 4
  %r_20.fp107 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 1
  %r_22.fp108 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 1
  %r_24.fp109 = load i32* %r_22.fp108, align 4
  %r_22.fp110 = load i32* %ptr_q.line7, align 4
  %r_25.fp111 = load i32* @ptr_MOD.line3, align 4
%r_26.fp112= srem i32 %r_22.fp110, %r_25.fp111
    store i32 %r_26.fp112, i32* %r_20.fp107, align 4
  %r_22.fp114 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 2
  %r_25.fp115 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 2
  %r_27.fp116 = load i32* %r_25.fp115, align 4
  %r_25.fp117 = load i32* %ptr_r.line7, align 4
  %r_28.fp118 = load i32* @ptr_MOD.line3, align 4
%r_29.fp119= srem i32 %r_25.fp117, %r_28.fp118
    store i32 %r_29.fp119, i32* %r_22.fp114, align 4
  %r_25.fp121 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 3
  %r_28.fp122 = getelementptr inbounds [ 4 x i32]* @ptr_mat.line1, i32 0, i32 3
  %r_30.fp123 = load i32* %r_28.fp122, align 4
  %r_28.fp124 = load i32* %ptr_s.line7, align 4
  %r_31.fp125 = load i32* @ptr_MOD.line3, align 4
%r_32.fp126= srem i32 %r_28.fp124, %r_31.fp125
    store i32 %r_32.fp126, i32* %r_25.fp121, align 4
br label %label.for.ix1.cond
label.for.ix1.cond:
  %r_28.fp128 = load i32* %ptr_x.line28para, align 4
%r_0.fp127= ashr i32 %r_28.fp128, 1
    store i32 %r_0.fp127, i32* %ptr_x.line28para, align 4
  br label %label.for.ix1.check
label.for.ix1.end:
  %r_28.fp129 = getelementptr inbounds [ 2 x i32]* %ptr_ans.line8, i32 0, i32 0
  %r_31.fp130 = load i32* %r_28.fp129, align 4
ret i32 %r_31.fp130
}
define i32 @main() #0
{
 %tmp_oneshot.fp131 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @ptr_n.line2)
  %r_28.fp132 = load i32* @ptr_n.line2, align 4
%r_31.fp133 = call i32 @solve( i32 %r_28.fp132 )
%tmp_oneshot.fp134 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_31.fp133)
ret i32 0
}

declare i32 @__isoc99_scanf(i8*, ...) #1
declare i32 @printf(i8*, ...) #1
attributes #0 = { nounwind uwtable "less-precise-fpmad"="false""no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
