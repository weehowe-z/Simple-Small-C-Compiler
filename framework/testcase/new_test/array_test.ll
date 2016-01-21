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

%ptr_0 =  getelementptr inbounds [5 x i32]* %ptr_a.line3, i32 0, i32 0
;#args# ->> #INIT: { ARGS }# ->> #DECS: VAR ASSIGN INIT# ->> #DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DEFS: TYPE DECS ; DEFS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  store i32 0, i32* %ptr_0, align 4
;#args# ->> #INIT: { ARGS }# ->> #DECS: VAR ASSIGN INIT# ->> #DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DECS: VAR, DECS# ->> #DEFS: TYPE DECS ; DEFS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

 %tmp_1 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %ptr_x.line3)
;#STMT: read ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_3 = load i32* %ptr_y.line3, align 4
;#EXPS: ID ARRS# ->> #=# ->> #EXP: EXPS# ->> #STMT: EXP ;# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

    store i32 8, i32* %ptr_y.line3, align 4
;#=# ->> #EXP: EXPS# ->> #STMT: EXP ;# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_5 = load i32* %ptr_z.line3, align 4
;#EXPS: ID ARRS# ->> #=# ->> #EXP: EXPS# ->> #STMT: EXP ;# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

    store i32 21, i32* %ptr_z.line3, align 4
;#=# ->> #EXP: EXPS# ->> #STMT: EXP ;# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_6 = load i32* %ptr_x.line3, align 4
;#EXPS: ID ARRS# ->> #STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%tmp_7 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_6)
;#STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_8 = load i32* %ptr_y.line3, align 4
;#EXPS: ID ARRS# ->> #STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%tmp_9 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_8)
;#STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_10 = load i32* %ptr_z.line3, align 4
;#EXPS: ID ARRS# ->> #STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%tmp_11 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_10)
;#STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_12 = getelementptr inbounds [ 5 x i32]* %ptr_a.line3, i32 0, i32 3
;#EXPS: ID ARRS# ->> #STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  %r_13 = load i32* %r_12, align 4
;#EXPS: ID ARRS# ->> #STMT: write ( EXPS )# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%tmp_14 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %r_13)
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

