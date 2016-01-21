@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
;#PROGRAM: EXTDEFS#

@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
;#PROGRAM: EXTDEFS#

define i32 @main() #0
;#FUNC: ID ( PARAS )# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

{
;#STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%r_0.fp0= icmp eq i32 1, 2
;#==# ->> #STMT: if ( EXPS ) STMT else STMT# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

 %tmp_oneshot.fp1 = icmp ne i1 %r_0.fp0, 0
;#STMT: if ( EXPS ) STMT else STMT# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

  br i1 %tmp_oneshot.fp1, label %label.if.ix1.then, label %label.if.ix1.else
 
;#STMT: if ( EXPS ) STMT else STMT# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

label.if.ix1.then:
;#STMT: if ( EXPS ) STMT else STMT# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%tmp_oneshot.fp2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 345)
;#STMT: write ( EXPS )# ->> #STMT: if ( EXPS ) STMT else STMT# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

br label %label.if.ix1.end
;#STMT: if ( EXPS ) STMT else STMT# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

label.if.ix1.else:
;#STMT: if ( EXPS ) STMT else STMT# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

%tmp_oneshot.fp3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 678)
;#STMT: write ( EXPS )# ->> #STMT: if ( EXPS ) STMT else STMT# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

br label %label.if.ix1.end
;#STMT: if ( EXPS ) STMT else STMT# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

label.if.ix1.end:
;#STMT: if ( EXPS ) STMT else STMT# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

ret i32 0
;#STMT: RETURN EXPS ;# ->> #STMTS: STMT STMTS# ->> #STMTS: STMT STMTS# ->> #STMTBLOCK: { DEFS STMTS }# ->> #EXTDEF: TYPE FUNC STMTBLOCK# ->> #EXTDEFS: EXTDEF EXTDEFS# ->> #PROGRAM: EXTDEFS#

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

