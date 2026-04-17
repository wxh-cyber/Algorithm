## 基础知识

<hr />

### 新四种类型转换

#### 1.`static_cast<T>(x)`

**用途:**普通类型转换、相关类指针转换、void\* 转回具体类型等。
**特点:**常用、语意清晰、编译期检查较多。

<br />

#### 2.`dynamic_cast<T>(x)`

**用途:**
主要用于“有继承关系”的安全向下转型<br />
**特点:**
运行时检查，更安全。<br />
**例如：**

```cpp
Base* b=new Derived();
Derived* d=dynamic_cast<Derived*>(b);
if(d){
    //转换成功
}
```

<br />

#### 3.`const_cast<T>(x)`

**用途:**
将 const 类型转换为非 const 类型<br />
去掉或添加`const/volatile`限定符。<br />
**特点:**
用于将 const 类型的指针转换为非 const 类型的指针，或将 const 类型的引用转换为非 const 类型的引用。
<br />

**例如：**

```cpp
const int a = 10;
int b = const_cast<int* >(&a);
```

<br />

#### 4.`reinterpret_cast<T>(x)`

**用途：**
按“底层比特/地址解释”进行转换<br />
**特点：**
最危险，最不安全，通常底层开发才用<br />

**例如：**

```cpp
int* p = reinterpret_cast<int*>(0x1234);
```

<br />
