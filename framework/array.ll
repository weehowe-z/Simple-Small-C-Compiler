@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
;#PROGRAM: EXTDEFS#

@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
;#PROGRAM: EXTDEFS#

define i32 @main() #0
;#FUNC: ID ( PARAS )# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

{
;#STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%ptr_x.line3  = alloca i32 , align 4
;#DECS: VAR, DECS# ->> #DEFS: TYPE DECS ; DEFS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%ptr_y.line3  = alloca i32 , align 4
;#DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DEFS: TYPE DECS ; DEFS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%ptr_z.line3  = alloca i32 , align 4
;#DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DEFS: TYPE DECS ; DEFS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%ptr_a.line3  = alloca [ 5 x i32] , align 4
;#DECS: VAR ASSIGN INIT# ->> #DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DEFS: TYPE DECS ; DEFS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%tmp_oneshot.fp0 =  getelementptr inbounds [5 x i32]* %ptr_a.line3, i32 0, i32 0
;#args# ->> #INIT: { ARGS }# ->> #DECS: VAR ASSIGN INIT# ->> #DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DEFS: TYPE DECS ; DEFS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  store i32 0, i32* %tmp_oneshot.fp0, align 4
;#args# ->> #INIT: { ARGS }# ->> #DECS: VAR ASSIGN INIT# ->> #DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DEFS: TYPE DECS ; DEFS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

 %tmp_oneshot.fp1 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %ptr_x.line3)
;#STMT: read ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_3.fp3 = load i32* %ptr_y.line3, align 4
;#EXPS: ID ARRS# ->> #=# ->> #EXP: EXPS# ->> #STMT: EXP ;# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

    store i32 8, i32* %ptr_y.line3, align 4
;#=# ->> #EXP: EXPS# ->> #STMT: EXP ;# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_0.fp5 = load i32* %ptr_z.line3, align 4
;#EXPS: ID ARRS# ->> #=# ->> #EXP: EXPS# ->> #STMT: EXP ;# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

    store i32 21, i32* %ptr_z.line3, align 4
;#=# ->> #EXP: EXPS# ->> #STMT: EXP ;# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_0.fp6 = load i32* %ptr_x.line3, align 4
;#EXPS: ID ARRS# ->> #STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%tmp_oneshot.fp7 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_0.fp6)
;#STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_0.fp8 = load i32* %ptr_y.line3, align 4
;#EXPS: ID ARRS# ->> #STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%tmp_oneshot.fp9 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_0.fp8)
;#STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_0.fp10 = load i32* %ptr_z.line3, align 4
;#EXPS: ID ARRS# ->> #STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%tmp_oneshot.fp11 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_0.fp10)
;#STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_0.fp12 = getelementptr inbounds [ 5 x i32]* %ptr_a.line3, i32 0, i32 3
;#EXPS: ID ARRS# ->> #STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_1.fp13 = load i32* %r_0.fp12, align 4
;#EXPS: ID ARRS# ->> #STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%tmp_oneshot.fp14 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_1.fp13)
;#STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

ret i32 0
;#STMT: RETURN EXPS ;# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

}
;#STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#


declare i32 @__isoc99_scanf(i8*, ...) #1
;#PROGRAM: EXTDEFS#

declare i32 @printf(i8*, ...) #1
;#PROGRAM: EXTDEFS#

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false""no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
;#PROGRAM: EXTDEFS#

attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
;#PROGRAM: EXTDEFS#

