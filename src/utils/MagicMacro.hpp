#pragma once
#include <nlohmann/json.hpp>

using ConstStringRef = const std::string&;

// splitter of given arg type of name
#define LPAREN (
#define RPAREN )
#define COMMA ,

#define CAT2(L, R) CAT2_(L, R)
#define CAT2_(L, R) L ## R
#define EXPAND2(...) __VA_ARGS__

#define SPLIT(OP, D) EXPAND2(OP CAT2(SPLIT_, D) RPAREN)

#define SPLIT_int LPAREN int COMMA
#define SPLIT_bool LPAREN bool COMMA
#define SPLIT_char LPAREN char COMMA
#define SPLIT_float LPAREN float COMMA
#define SPLIT_double LPAREN double COMMA
#define SPLIT_uintptr_t LPAREN uintptr_t COMMA
#define SPLIT_ConstStringRef LPAREN ConstStringRef COMMA

#define DECLARE_VARIABLE_NATIVELY_(x, y) x y = params[#y]
#define DECLARE_VARIABLE_NATIVELY(A) SPLIT(DECLARE_VARIABLE_NATIVELY_, A)

#define CREATE_FUNCTION_CALL_ARG_(x, y) y
#define CREATE_FUNCTION_CALL_ARG(A) EXPAND2(SPLIT(CREATE_FUNCTION_CALL_ARG_, A))

#define CREATE_RETURN_OBJECT_ELEMENT_(x, y) retJson[#y] = y
#define CREATE_RETURN_OBJECT_ELEMENT(A) EXPAND2(SPLIT(CREATE_RETURN_OBJECT_ELEMENT_, A))

#ifdef _MSC_VER
#define OMP_IPC__NUM_ARGS(...) OMP_IPC__NUM_ARGS_(OMP_IPC__NUM_ARGS_MSVC(__VA_ARGS__))

#define OMP_IPC__NUM_ARGS_MSVC(...) unused, __VA_ARGS__
#define OMP_IPC__NUM_ARGS_(...) EXPAND(OMP_IPC__NUM_ARGS_IMPL(__VA_ARGS__, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#define OMP_IPC__NUM_ARGS_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, N, ...) N
#else
#define OMP_IPC__NUM_ARGS(...) OMP_IPC__NUM_ARGS_(__VA_ARGS__)
#define OMP_IPC__NUM_ARGS_(...) OMP_IPC__NUM_ARGS_IMPL(0, ##__VA_ARGS__, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define OMP_IPC__NUM_ARGS_IMPL(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, N, ...) N
#endif

#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a##__VA_ARGS__

#define EMPTY()
#define DEFER(id) id EMPTY()
#define OBSTRUCT(...) __VA_ARGS__ DEFER(EMPTY)()
#define EXPAND(...) __VA_ARGS__

#define EVAL(...) EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))
#define EVAL5(...) __VA_ARGS__

#define PREPEND_ARGS_TO_DECLARE_VARS_0(a)
#define PREPEND_ARGS_TO_DECLARE_VARS_1(a)       DECLARE_VARIABLE_NATIVELY(a);
#define PREPEND_ARGS_TO_DECLARE_VARS_2(a, ...)  DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_1 (__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_3(a, ...)  DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_2 (__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_4(a, ...)  DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_3 (__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_5(a, ...)  DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_4 (__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_6(a, ...)  DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_5 (__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_7(a, ...)  DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_6 (__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_8(a, ...)  DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_7 (__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_9(a, ...)  DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_8 (__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_10(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_9 (__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_11(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_10(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_12(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_11(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_13(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_12(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_14(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_13(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_15(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_14(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_16(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_15(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_17(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_16(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_18(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_17(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_19(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_18(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_20(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_19(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_21(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_20(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_22(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_21(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_23(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_22(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_24(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_23(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_25(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_24(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_26(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_25(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_27(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_26(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_28(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_27(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_29(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_28(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_30(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_29(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_31(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_30(__VA_ARGS__))
#define PREPEND_ARGS_TO_DECLARE_VARS_32(a, ...) DECLARE_VARIABLE_NATIVELY(a); EVAL(PREPEND_ARGS_TO_DECLARE_VARS_31(__VA_ARGS__))

#define PREPEND_ARGS_IN_FUNCTION_CALL_0(a)
#define PREPEND_ARGS_IN_FUNCTION_CALL_1(a)       CREATE_FUNCTION_CALL_ARG(a),
#define PREPEND_ARGS_IN_FUNCTION_CALL_2(a, ...)  CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_1 (__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_3(a, ...)  CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_2 (__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_4(a, ...)  CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_3 (__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_5(a, ...)  CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_4 (__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_6(a, ...)  CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_5 (__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_7(a, ...)  CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_6 (__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_8(a, ...)  CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_7 (__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_9(a, ...)  CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_8 (__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_10(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_9 (__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_11(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_10(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_12(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_11(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_13(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_12(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_14(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_13(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_15(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_14(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_16(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_15(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_17(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_16(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_18(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_17(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_19(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_18(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_20(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_19(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_21(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_20(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_22(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_21(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_23(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_22(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_24(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_23(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_25(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_24(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_26(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_25(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_27(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_26(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_28(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_27(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_29(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_28(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_30(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_29(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_31(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_30(__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_32(a, ...) CREATE_FUNCTION_CALL_ARG(a), EVAL(PREPEND_ARGS_IN_FUNCTION_CALL_31(__VA_ARGS__))

#define GENERATE_RETURN_VAR_()
#define GENERATE_RETURN_VAR_0()
#define GENERATE_RETURN_VAR_1(a)       CREATE_RETURN_OBJECT_ELEMENT(a);
#define GENERATE_RETURN_VAR_2(a, ...)  CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_1 (__VA_ARGS__))
#define GENERATE_RETURN_VAR_3(a, ...)  CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_2 (__VA_ARGS__))
#define GENERATE_RETURN_VAR_4(a, ...)  CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_3 (__VA_ARGS__))
#define GENERATE_RETURN_VAR_5(a, ...)  CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_4 (__VA_ARGS__))
#define GENERATE_RETURN_VAR_6(a, ...)  CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_5 (__VA_ARGS__))
#define GENERATE_RETURN_VAR_7(a, ...)  CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_6 (__VA_ARGS__))
#define GENERATE_RETURN_VAR_8(a, ...)  CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_7 (__VA_ARGS__))
#define GENERATE_RETURN_VAR_9(a, ...)  CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_8 (__VA_ARGS__))
#define GENERATE_RETURN_VAR_10(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_9 (__VA_ARGS__))
#define GENERATE_RETURN_VAR_11(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_10(__VA_ARGS__))
#define GENERATE_RETURN_VAR_12(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_11(__VA_ARGS__))
#define GENERATE_RETURN_VAR_13(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_12(__VA_ARGS__))
#define GENERATE_RETURN_VAR_14(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_13(__VA_ARGS__))
#define GENERATE_RETURN_VAR_15(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_14(__VA_ARGS__))
#define GENERATE_RETURN_VAR_16(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_15(__VA_ARGS__))
#define GENERATE_RETURN_VAR_17(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_16(__VA_ARGS__))
#define GENERATE_RETURN_VAR_18(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_17(__VA_ARGS__))
#define GENERATE_RETURN_VAR_19(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_18(__VA_ARGS__))
#define GENERATE_RETURN_VAR_20(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_19(__VA_ARGS__))
#define GENERATE_RETURN_VAR_21(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_20(__VA_ARGS__))
#define GENERATE_RETURN_VAR_22(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_21(__VA_ARGS__))
#define GENERATE_RETURN_VAR_23(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_22(__VA_ARGS__))
#define GENERATE_RETURN_VAR_24(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_23(__VA_ARGS__))
#define GENERATE_RETURN_VAR_25(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_24(__VA_ARGS__))
#define GENERATE_RETURN_VAR_26(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_25(__VA_ARGS__))
#define GENERATE_RETURN_VAR_27(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_26(__VA_ARGS__))
#define GENERATE_RETURN_VAR_28(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_27(__VA_ARGS__))
#define GENERATE_RETURN_VAR_29(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_28(__VA_ARGS__))
#define GENERATE_RETURN_VAR_30(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_29(__VA_ARGS__))
#define GENERATE_RETURN_VAR_31(a, ...) CREATE_RETURN_OBJECT_ELEMENT(a); EVAL(GENERATE_RETURN_VAR_30(__VA_ARGS__))

#define PREPEND_ARGS_TO_DECLARE_VARS_IMPL(...) EVAL(CAT2(PREPEND_ARGS_TO_DECLARE_VARS_, OMP_IPC__NUM_ARGS(__VA_ARGS__)) (__VA_ARGS__))
#define PREPEND_ARGS_IN_FUNCTION_CALL_IMPL(...) EVAL(CAT2(PREPEND_ARGS_IN_FUNCTION_CALL_, OMP_IPC__NUM_ARGS(__VA_ARGS__)) (__VA_ARGS__))
#define GENERATE_RETURN_VAR_IMPL(...) EVAL(CAT2(GENERATE_RETURN_VAR_, OMP_IPC__NUM_ARGS(__VA_ARGS__)) (__VA_ARGS__))

#define GENERATE_PARAMS_TO_DECLARE_VARS(...) PREPEND_ARGS_TO_DECLARE_VARS_IMPL(__VA_ARGS__)
#define GENERATE_PARAMS_TO_USE_IN_FUNCTION_SIG(...) __VA_ARGS__
#define GENERATE_PARAMS_TO_USE_IN_FUNCTION_CALL(...) PREPEND_ARGS_IN_FUNCTION_CALL_IMPL(__VA_ARGS__)
#define IPC_RETURN(...) nlohmann::json retJson; \
	retJson["success"] = true; \
	GENERATE_RETURN_VAR_IMPL(__VA_ARGS__) \
	return RETURN_VALUE(retJson);

// name: name for IPC event sent from clients (other languages)
// params: params in nlohmann::json object
#define IPC_API(name, ...)																											\
	class MessageHandler_##name : public MessageHandler																				\
	{																																\
	public:																															\
		MessageHandler_##name() {																									\
			MessageHandler::name_ = #name;																							\
			MessageHandlerPool::Get()->Register(this);																				\
		}																															\
																																	\
		~MessageHandler_##name()																									\
		{																															\
			MessageHandlerPool::Get()->UnRegister(this);																			\
		}																															\
																																	\
		nlohmann::json Call(const nlohmann::json& params, MessageSocket* messageSocket) override									\
		{																															\
			GENERATE_PARAMS_TO_DECLARE_VARS(__VA_ARGS__)																			\
			return CallOuter(GENERATE_PARAMS_TO_USE_IN_FUNCTION_CALL(__VA_ARGS__) messageSocket);									\
		}																															\
																																	\
private:																															\
		nlohmann::json CallOuter(GENERATE_PARAMS_TO_USE_IN_FUNCTION_SIG(__VA_ARGS__), MessageSocket* messageSocket);				\
	};																																\
																																	\
	MessageHandler_##name ipc_api_##name;																							\
																																	\
	nlohmann::json MessageHandler_##name::CallOuter(GENERATE_PARAMS_TO_USE_IN_FUNCTION_SIG(__VA_ARGS__), MessageSocket* messageSocket)	

// name: name for IPC event sent from clients (other languages)
// params: params in nlohmann::json object
// messageSocket: an instance of relevant messageSocket
#define IPC_API_EX(name, params, messageSocket)                                      \
	class MessageHandler_##name : public MessageHandler                              \
	{                                                                                \
	public:                                                                          \
		MessageHandler_##name() {                                                    \
			MessageHandler::name_ = #name;                                           \
			MessageHandlerPool::Get()->Register(this);                               \
		}                                                                            \
																					 \
		~MessageHandler_##name()                                                     \
		{                                                                            \
			MessageHandlerPool::Get()->UnRegister(this);                             \
		}                                                                            \
																					 \
		nlohmann::json Call(params, messageSocket) override;                         \
	};                                                                               \
																					 \
	MessageHandler_##name ipc_api_##name;                                            \
																					 \
	nlohmann::json MessageHandler_##name::Call(params, messageSocket)                \


#define RETURN_VALUE(x) returnValue(x)
#define RETURN_ERROR(x) returnError(x)
#define UNDEFINED_FAILED_RETURN(x) RETURN_ERROR("undefined error")
#define FUNCTION_FAIL_RETURN RETURN_ERROR(this->name_ + ": error while executing.")
#define NO_DATA_SUCCESS_RETURN RETURN_VALUE()

template<typename T>
inline nlohmann::json returnError(T value)
{
	nlohmann::json obj;
	obj["error"] = value;
	obj["success"] = false;
	return obj;
}

inline nlohmann::json returnValue(const nlohmann::json& value)
{
	nlohmann::json obj;
	obj = value;
	// Let's not set it here, instead let's set it in `IPC_RETURN` because user might want to change `success` prop by their own
	// obj["success"] = true;
	obj["error"] = nullptr;
	return obj;
}
