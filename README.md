Turkish Sentiment Lexicon (HisNet)
============

# Polarity Lexicons

Exploiting a dictionary-based method necessitates the construction of a specific polarity dictionary in the same language as the data-to-be-analyzed. The reason behind this necessity stems from the improbability of creating a universal polarity dictionary due to both grammatical and cultural asymmetries between languages. For instance, a certain historical event can have positive connotations in one culture and negative connotations in another culture. Thus, it is an essential step to create a language specific polarity dictionary.

The first examples of polarity dictionary work could be found in English. SentiWordNet 1.0, the very first study on English polarity dictionaries, was presented by Esuli and Sebastiani (2006). Considerable research has been conducted to improve these resources with the aim of making them more precise. For example, the polarities of the objective words in SentiWordNet have been reassessed by Hung and Lini (2010). SenticNet (Cambria et al., 2014), another well-known dictionary in English, is created by rescoring words based on five different criteria, which are happiness, attention, sensitivity, ability and general polarity. Thus, it is evident that SenticNet is a polarity dictionary that provides a more extensive emotional evaluation than SentiWordNet.

There are polar dictionaries created in major languages other than English. However, these dictionaries were found to be insufficient in terms of the number of words. Brooke et al. (2009) aimed to translate English polarity sources to Spanish. At first, the methods established independent from the target language were found adequate, yet in the long term it was noticed that these methods were costly and inaccurate. Employing language-dependent resources to improve this system was deemed more feasible. Remus et al. (2010) have created a German sensitivity dictionary named SentiWortschatz for the German language. For the purpose of creating a feeling dictionary, over 3500 German words were assigned positive and nega- tive values in the range of [-1, 1], using PosTags. Abdaoui et al. (2017) have created the FEEL: a French Expanded Emotion Lexicon polarity dictionary for French. Moreno-Sandoval et al. (2017) have created the Combined Spanish Lexicon polarity dictionary for Spanish.

# Turkish Polarity Lexicon HisNet

In this study, we present a polarity dictionary to provide an extensive polarity dictionary for Turkish that dictionary-based sentiment analysis studies have been longing for. Our primary objective is to provide a more refined and extensive polarity dictionary than the previous SentiTurkNet. In doing so, we have resorted to a different network from the referenced study. We have identified approximately 76,825 synsets from Kenet, which then were manually labeled as positive, negative or neutral by three native speakers of Turkish. The first labelling process resulted in 3,100 positive, 10,191 negative and 63,534 neutral data, during which decisions were based on the meaning and connotation of each word. 

Subsequently, a second labeling was further made on positive and negative words as strong or weak based on their degree of positivity or negativity. For instance, the word mükemmel (excellent) in Turkish has been marked three times. Thus, three different views were obtained for the value of this word. While selecting the appropriate label, the compatibility of the labels selected by the three labelers was also evaluated. To put it differently, if a positive word receives strong label from all three annotators, it is regarded as strong positive. If it receives two strong and one weak label, it is considered as very positive. If it is la- belled as strong once and as weak twice, it means it is just positive. Finally, if it receives weak label from all three annotators, it is considered as weak positive. The same is also true for the words labelled as negative.

|Polarity Level|# of Synsets|
|---|---|
|Strongly positive|1,038|
|Very positive|451|
|Positive|456|
|Weakly positive|1,234|
|Objective|63,534|
|Strongly negative|4,430|
|Very negative|1,465|
|Negative|1,238|
|Weakly negative|3,360|

Simple Web Interface For Sentiment Lexicon
============
[Link 1](http://104.247.163.162/nlptoolkit/turkish-sentinet.html) [Link 2](https://starlangsoftware.github.io/nlptoolkit-web-simple/turkish-sentinet.html)

Video Lectures
============

[<img src="https://github.com/StarlangSoftware/TurkishSentiNet/blob/master/video1.jpg" width="50%">](https://youtu.be/CdHSwgq2lTE)[<img src="https://github.com/StarlangSoftware/TurkishSentiNet/blob/master/video2.jpg" width="50%">](https://youtu.be/_tbrvPlG87Y)[<img src="https://github.com/StarlangSoftware/TurkishSentiNet/blob/master/video3.jpg" width="50%">](https://youtu.be/CUbNz34Ac5c)

For Developers
============

You can also see [Java](https://github.com/starlangsoftware/TurkishSentiNet), 
[Python](https://github.com/starlangsoftware/TurkishSentiNet-Py), 
[Cython](https://github.com/starlangsoftware/TurkishSentiNet-Cy), [C++](https://github.com/starlangsoftware/TurkishSentiNet-CPP),
[Swift](https://github.com/starlangsoftware/TurkishSentiNet-Swift), 
[Js](https://github.com/starlangsoftware/TurkishSentiNet-Js), [Php](https://github.com/starlangsoftware/TurkishSentiNet-Php), or [C#](https://github.com/starlangsoftware/TurkishSentiNet-CS) repository.

## Requirements

* [C Compiler](#cpp)
* [Git](#git)


### CPP
To check if you have compatible C Compiler installed,
* Open CLion IDE 
* Preferences >Build,Execution,Deployment > Toolchain  

### Git

Install the [latest version of Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Download Code

In order to work on code, create a fork from GitHub page. 
Use Git for cloning the code to your local or below line for Ubuntu:

	git clone <your-fork-git-link>

A directory called SentiNet-C will be created. Or you can use below link for exploring the code:

	git clone https://github.com/starlangsoftware/TurkishSentiNet-C.git

## Open project with CLion IDE

To import projects from Git with version control:

* Open CLion IDE , select Get From Version Control.

* In the Import window, click URL tab and paste github URL.

* Click open as Project.

Result: The imported project is listed in the Project Explorer view and files are loaded.


## Compile

**From IDE**

After being done with the downloading and opening project, select **Build Project** option from **Build** menu. After compilation process, user can run Math-CPP.

Detailed Description
============

+ [SentiNet](#sentinet)
+ [SentiSynSet](#sentisynset)

## SentiNet

Duygu sözlüğünü yüklemek için

	a = create_senti_net()

Belirli bir synsete ait duygu synsetini elde etmek için

	Senti_synset_ptr get_senti_synset(char* id)

## SentiSynSet

Bir SentiSynset elimizdeyken onun pozitif skorunu

	positive_score

negatif skorunu

	negative_score

polaritysini

	Polarity_type get_polarity_of_synset()

# Cite

	@inproceedings{ozcelik21,
 	title={{H}is{N}et: {A} {P}olarity {L}exicon based on {W}ord{N}et for {E}motion {A}nalysis},
 	year={2021},
 	author={M. Ozcelik and B. N. Arican and O. Bakay and E. Sarmis and N. B. Bayazit and O. Ergelen and O. T. Y{\i}ld{\i}z},
 	booktitle={Proceedings of GWC 2021}
 	}

For Contibutors
============

### Conan Setup

1. First install conan.

pip install conan

Instructions are given in the following page:

https://docs.conan.io/2/installation.html

2. Add conan remote 'ozyegin' with IP: 104.247.163.162 with the following command:

conan remote add ozyegin http://104.247.163.162:8081/artifactory/api/conan/conan-local --insert

3. Use the comman conan list to check for installed packages. Probably there are no installed packages.

conan list

### conanfile.py file

1. Put the correct dependencies in the requires part
```
    requires = ["math_c/1.0.0", "data_structure_c/1.0.0", "classification_c/1.0.0"]
```

2. Default settings are:
```
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": True}
    exports_sources = "src/*", "Test/*"

    def layout(self):
        cmake_layout(self, src_folder="src")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(conanfile=self, keep_path=False, src=join(self.source_folder), dst=join(self.package_folder, "include"), pattern="*.h")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.a")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.so")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.dylib")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "bin"), pattern="*.dll")

    def package_info(self):
        self.cpp_info.libs = ["ComputationalGraph"]
```

### CMakeLists.txt file
1. Set the C standard with compiler flags.
```
	set(CMAKE_C_STANDARD 17)
	set(CMAKE_C_FLAGS "-O3")
```
2. Dependent packages should be given with find_package.
```
	find_package(util_c REQUIRED)
	find_package(data_structure_c REQUIRED)
```
3. For library part, use add_library and target_link_libraries commands. Use m library for math linker in Linux.
```
	add_library(Math src/Distribution.c src/Distribution.h src/DiscreteDistribution.c src/DiscreteDistribution.h src/Vector.c src/Vector.h src/Eigenvector.c src/Eigenvector.h src/Matrix.c src/Matrix.h src/Tensor.c src/Tensor.h)
	target_link_libraries(Math util_c::util_c data_structure_c::data_structure_c m)
```
4. For executable tests, use add_executable and target_link_libraries commands. Use m library for math linker in Linux.
```
	add_executable(DiscreteDistributionTest src/Distribution.c src/Distribution.h src/DiscreteDistribution.c src/DiscreteDistribution.h src/Vector.c src/Vector.h src/Eigenvector.c src/Eigenvector.h src/Matrix.c src/Matrix.h src/Tensor.c src/Tensor.h Test/DiscreteDistributionTest.c)
	target_link_libraries(DiscreteDistributionTest util_c::util_c data_structure_c::data_structure_c m)
```

### Data files
1. Add data files to the cmake-build-debug folder.

### C files
1. Define structs as class counterparts.
```
	typedef struct {
	    double *data;       // Flattened data array
 	   	int *shape;         // Shape of the tensor
	    int *strides;       // Strides for each dimension
 	   	int dimensions;     // Number of dimensions
  	  	int total_elements;
	} Tensor;
```
2. Define also typedefs for pointer to those structs.
```
	typedef Tensor *Tensor_ptr;
```
3. Put all those definitions to the header files with prototypes of functions.
4. Constructor method(s) should allocate a pointer of struct and fill the details and return the pointer.
```
Vector_ptr create_vector(Array_list_ptr values) {
    Vector_ptr result = malloc_(sizeof(Vector));
    result->values = values;
    result->size = values->size;
    return result;
}
```
5. Destructor method should be defined for each struct and deallocate the object and its contents if allocated.
```
void free_vector(Vector_ptr vector) {
    free_array_list(vector->values, free_);
    free_(vector);
}
```
6. If there is multiple inheritance, then define the super class inside the subclass, which also should be defined inside its own subclass etc.
```
struct sgd_momentum {
    Optimizer optimizer;
    Hash_map_ptr velocity_map;
    double momentum;
};
struct Adam {
    Sgd_momentum sgd;
    Hash_map_ptr momentum_map;
    double beta2;
    double epsilon;
    double current_beta1;
    double current_beta2;
};
struct AdamW {
    Adam adam;
    double weight_decay;
};
```
7. If there is overloading, and subclasses should override the method, you can add pointers to the functions and set them in the constructor.
```
struct function {
    Function_type function_type;
    Tensor_ptr (*calculate)(const void*, const Tensor*);
    Tensor_ptr (*derivative)(const void*, const Tensor*, const Tensor*);
};
Elu_ptr create_elu(const double a) {
    Elu_ptr delu = malloc_(sizeof(Elu));
    delu->a = a;
    delu->function.function_type = ELU;
    delu->function.calculate = calculate_elu;
    delu->function.derivative = derivative_elu;
    return delu;
}
```
8. Instanceof could be done using an enumerated type defined in the parent class.
```
enum optimizer_type {
    OPTIMIZER, ADAM, ADAM_W, SGD_MOMENTUM, SGD,
};
typedef enum optimizer_type Optimizer_type;
struct optimizer {
    Optimizer_type type;
```
9. If needed, hash function should be declared for the struct.
```
	unsigned int hash_function_computational_node(const Computational_node *node, int N) {
    	return ((uintptr_t)node) % N;
	}
```
10. If needed, comparator function should be declared for the struct.
```
int compare_annotated_word(const Annotated_word *word1, const Annotated_word *word2) {
    return compare_string(word1->name, word2->name);
}
```
11. Data Structures: For hashmap, linked hash map and hashset, use create_hash_map, create_linked_hash_map, and create_hash_set in data structure library. There are default string and integer versions of hash_map.
```
Hash_map_ptr create_hash_map(unsigned int (*hash_function)(const void *, int), int (*key_compare)(const void *, const void *));
Linked_hash_map_ptr create_linked_hash_map(unsigned int (*hash_function)(const void *, int), int (*compare)(const void *, const void *));
Hash_map_ptr create_string_hash_map();
Hash_map_ptr create_integer_hash_map();
Hash_set_ptr create_hash_set(unsigned int (*hash_function)(const void *, int), int (*compare)(const void *, const void *));
```
12. Data Structures: For array list, use create_array_list in data structure library..
```
Array_list_ptr create_array_list();
```
13. Data Structures: For linked list, use linked_list in data structure library..
```
Linked_list_ptr create_linked_list(int (*compare)(const void *, const void *));
```
14. Data Structures: For queue and stack, use queue and stack in data structure library.
```
Queue_ptr create_queue();
Stack_ptr create_stack();
```
15. Data Structures: For hash map that is counting items, use counter hash map in data structure library.
```
Counter_hash_map_ptr
create_counter_hash_map(unsigned int (*hash_function)(const void *, int), int (*key_compare)(const void *, const void *));
```
16. Do not forget to comment each function.
```
	/**
 	* Initializes a tensor with given data and shape. Data is cloned in the tensor
	*
 	* @param data Flattened array representing the tensor data.
 	* @param shape Array representing the shape of the tensor.
 	* @param dimensions Size of the shape array.
 	* @return Pointer to the created tensor. Returns NULL on failure.
 	*/
	Tensor_ptr create_tensor(const double *data, const int *shape, int dimensions) {
```
17. Function names should follow snake case case.
```
	Tensor_ptr tensor_get(const Tensor *tensor, const int *dimensions, int size) {
```
18. All heap allocations should be done with malloc_, calloc_, realloc_ taken from the memory management library.
```
    int *new_shape = malloc_((tensor->dimensions - size) * sizeof(int));
```
19. All heap deallocations should be done with free_ taken from the memory management library.
```
    free_(new_shape);
```
20. DO NOT write getter and setter methods.
21. If there are multiple constructors for a class, define them as constructor1, constructor2, ....
```
Tensor_ptr create_tensor(const double *data, const int *shape, int dimensions);

Tensor_ptr create_tensor2(const int *shape, int dimensions);

Tensor_ptr create_tensor3(double *data, const int *shape, int dimensions);

Tensor_ptr create_tensor4(const int *shape, int dimensions);
```
22. Use separate main method for testing purposes.
```
int main() {
    start_medium_memory_check();
    testColumnWiseNormalize();
    testMultiplyWithConstant();
    testDivideByConstant();
    end_memory_check();
}
```
23. Testing main method should start with memory check and end with memory check.
```
int main() {
    start_medium_memory_check();
    testColumnWiseNormalize();
    testMultiplyWithConstant();
    testDivideByConstant();
    end_memory_check();
}
```
24. Enumerated types should be declared with enum.
```
enum category_type{
    MATHEMATICS, SPORT, MUSIC, SLANG, BOTANIC,
    PLURAL, MARINE, HISTORY, THEOLOGY, ZOOLOGY,
    METAPHOR, PSYCHOLOGY, ASTRONOMY, GEOGRAPHY, GRAMMAR,
    MILITARY, PHYSICS, PHILOSOPHY, MEDICAL, THEATER,
    ECONOMY, LAW, ANATOMY, GEOMETRY, BUSINESS,
    PEDAGOGY, TECHNOLOGY, LOGIC, LITERATURE, CINEMA,
    TELEVISION, ARCHITECTURE, TECHNICAL, SOCIOLOGY, BIOLOGY,
    CHEMISTRY, GEOLOGY, INFORMATICS, PHYSIOLOGY, METEOROLOGY,
    MINERALOGY
};
```
25. Every header file should start with
```
#ifndef MATH_DISTRIBUTION_H
#define MATH_DISTRIBUTION_H
```
and end with
```
#endif //MATH_DISTRIBUTION_H
```
26. Use regular package for regular expression handling.
```
	void check_match(char* expression, char* word){
    	Regular_expression_ptr re = create_regular_expression(expression);
    	if (!full_matches(re, word)){
        	printf("Mismatch %s %s\n", re->expression, word);
    	}
    	free_regular_expression(re);
	}
```
27. Do not forget to use const expression for parameters, if they will not be changed in the function.
```
bool frame_lexical_unit_exists(const Frame* frame, const char *synSetId);
```
28. For dynamic string handling, use util package with stringutils.
```
struct string {
    char *s;
    int max_size;
};
typedef struct string String;
typedef String *String_ptr;
String_ptr create_string();
String_ptr create_string2(const char *s);
String_ptr create_string3(const char* s1, const char* s2);
String_ptr create_string4(const char* s1, const char* s2, const char* s3);
```
29. Foor boolean type, use bool.
```
bool check_definition(const Data_set* data_set, const Instance* instance);
```
30. Use xmlparser package for parsing xml files.
```
    Xml_document_ptr doc = create_xml_document("test.xml");
