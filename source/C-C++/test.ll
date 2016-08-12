; ModuleID = 'test.bc'
source_filename = "test.cpp"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

; Function Attrs: nounwind ssp uwtable
define i32* @_Z4funci(i32) #0 {
  %2 = alloca i32, align 4
  %3 = alloca [16 x i32], align 16
  store i32 %0, i32* %2, align 4
  %4 = getelementptr inbounds [16 x i32], [16 x i32]* %3, i64 0, i64 0
  store i32 100, i32* %4, align 16
  %5 = getelementptr inbounds [16 x i32], [16 x i32]* %3, i64 0, i64 15
  store i32 200, i32* %5, align 4
  %6 = getelementptr inbounds [16 x i32], [16 x i32]* %3, i32 0, i32 0
  ret i32* %6
}

attributes #0 = { nounwind ssp uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"Apple LLVM version 8.0.0 (clang-800.0.33.1)"}
