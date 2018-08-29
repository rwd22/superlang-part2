; ModuleID = 'find.cpp'
source_filename = "find.cpp"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.13.0"

@_ZZ4mainE1a = private unnamed_addr constant [8 x i32] [i32 6, i32 4, i32 42, i32 0, i32 1024, i32 1, i32 -4, i32 12], align 16

; Function Attrs: norecurse ssp uwtable
define i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %a = alloca [8 x i32], align 16
  %n = alloca i32, align 4
  %p = alloca i32*, align 8
  %ref.tmp = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  %0 = bitcast [8 x i32]* %a to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %0, i8* bitcast ([8 x i32]* @_ZZ4mainE1a to i8*), i64 32, i32 16, i1 false)
  store i32 8, i32* %n, align 4
  %arraydecay = getelementptr inbounds [8 x i32], [8 x i32]* %a, i32 0, i32 0
  %arraydecay1 = getelementptr inbounds [8 x i32], [8 x i32]* %a, i32 0, i32 0
  %1 = load i32, i32* %n, align 4
  %idx.ext = sext i32 %1 to i64
  %add.ptr = getelementptr inbounds i32, i32* %arraydecay1, i64 %idx.ext
  store i32 0, i32* %ref.tmp, align 4
  %call = call i32* @_Z4findIPiiET_S1_S1_RKT0_(i32* %arraydecay, i32* %add.ptr, i32* dereferenceable(4) %ref.tmp)
  store i32* %call, i32** %p, align 8
  %2 = load i32*, i32** %p, align 8
  %arraydecay2 = getelementptr inbounds [8 x i32], [8 x i32]* %a, i32 0, i32 0
  %sub.ptr.lhs.cast = ptrtoint i32* %2 to i64
  %sub.ptr.rhs.cast = ptrtoint i32* %arraydecay2 to i64
  %sub.ptr.sub = sub i64 %sub.ptr.lhs.cast, %sub.ptr.rhs.cast
  %sub.ptr.div = sdiv exact i64 %sub.ptr.sub, 4
  %conv = trunc i64 %sub.ptr.div to i32
  ret i32 %conv
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i32, i1) #1

; Function Attrs: nounwind ssp uwtable
define linkonce_odr i32* @_Z4findIPiiET_S1_S1_RKT0_(i32* %first, i32* %last, i32* dereferenceable(4) %value) #2 {
entry:
  %retval = alloca i32*, align 8
  %first.addr = alloca i32*, align 8
  %last.addr = alloca i32*, align 8
  %value.addr = alloca i32*, align 8
  store i32* %first, i32** %first.addr, align 8
  store i32* %last, i32** %last.addr, align 8
  store i32* %value, i32** %value.addr, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end, %entry
  %0 = load i32*, i32** %first.addr, align 8
  %1 = load i32*, i32** %last.addr, align 8
  %cmp = icmp ne i32* %0, %1
  br i1 %cmp, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %2 = load i32*, i32** %first.addr, align 8
  %3 = load i32, i32* %2, align 4
  %4 = load i32*, i32** %value.addr, align 8
  %5 = load i32, i32* %4, align 4
  %cmp1 = icmp eq i32 %3, %5
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %while.body
  %6 = load i32*, i32** %first.addr, align 8
  store i32* %6, i32** %retval, align 8
  br label %return

if.end:                                           ; preds = %while.body
  %7 = load i32*, i32** %first.addr, align 8
  %incdec.ptr = getelementptr inbounds i32, i32* %7, i32 1
  store i32* %incdec.ptr, i32** %first.addr, align 8
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %8 = load i32*, i32** %last.addr, align 8
  store i32* %8, i32** %retval, align 8
  br label %return

return:                                           ; preds = %while.end, %if.then
  %9 = load i32*, i32** %retval, align 8
  ret i32* %9
}

attributes #0 = { norecurse ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { nounwind ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"clang version 4.0.0 (git@github.com:asutton/clang-reflect.git 8317e40b61d41300797ead958d7b7c9a13bed863) (git@github.com:llvm-mirror/llvm.git 650050c7c2061ec08da359b57e12ae7a4b8c8911)"}
