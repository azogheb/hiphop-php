/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
#include <runtime/ext_hhvm/ext_hhvm.h>
#include <runtime/base/builtin_functions.h>
#include <runtime/base/array/array_init.h>
#include <runtime/ext/ext.h>
#include <runtime/vm/class.h>
#include <runtime/vm/runtime.h>
#include <exception>

namespace HPHP {

/*
HPHP::Variant HPHP::f_gethostname()
_ZN4HPHP13f_gethostnameEv

(return value) => rax
_rv => rdi
*/

TypedValue* fh_gethostname(TypedValue* _rv) asm("_ZN4HPHP13f_gethostnameEv");

TypedValue* fg_gethostname(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 0LL) {
      fh_gethostname((&(rv)));
      if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
      frame_free_locals_no_this_inl(ar, 0);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("gethostname", 0, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_gethostbyaddr(HPHP::String const&)
_ZN4HPHP15f_gethostbyaddrERKNS_6StringE

(return value) => rax
_rv => rdi
ip_address => rsi
*/

TypedValue* fh_gethostbyaddr(TypedValue* _rv, Value* ip_address) asm("_ZN4HPHP15f_gethostbyaddrERKNS_6StringE");

TypedValue * fg1_gethostbyaddr(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_gethostbyaddr(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToStringInPlace(args-0);
  fh_gethostbyaddr((rv), &args[-0].m_data);
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_gethostbyaddr(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      if (IS_STRING_TYPE((args-0)->m_type)) {
        fh_gethostbyaddr((&(rv)), &args[-0].m_data);
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_gethostbyaddr(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("gethostbyaddr", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::String HPHP::f_gethostbyname(HPHP::String const&)
_ZN4HPHP15f_gethostbynameERKNS_6StringE

(return value) => rax
_rv => rdi
hostname => rsi
*/

Value* fh_gethostbyname(Value* _rv, Value* hostname) asm("_ZN4HPHP15f_gethostbynameERKNS_6StringE");

TypedValue * fg1_gethostbyname(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_gethostbyname(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfString;
  tvCastToStringInPlace(args-0);
  fh_gethostbyname((&rv->m_data), &args[-0].m_data);
  if (rv->m_data.num == 0LL) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_gethostbyname(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      if (IS_STRING_TYPE((args-0)->m_type)) {
        rv.m_type = KindOfString;
        fh_gethostbyname((&rv.m_data), &args[-0].m_data);
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_gethostbyname(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("gethostbyname", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_gethostbynamel(HPHP::String const&)
_ZN4HPHP16f_gethostbynamelERKNS_6StringE

(return value) => rax
_rv => rdi
hostname => rsi
*/

TypedValue* fh_gethostbynamel(TypedValue* _rv, Value* hostname) asm("_ZN4HPHP16f_gethostbynamelERKNS_6StringE");

TypedValue * fg1_gethostbynamel(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_gethostbynamel(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToStringInPlace(args-0);
  fh_gethostbynamel((rv), &args[-0].m_data);
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_gethostbynamel(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      if (IS_STRING_TYPE((args-0)->m_type)) {
        fh_gethostbynamel((&(rv)), &args[-0].m_data);
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_gethostbynamel(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("gethostbynamel", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_getprotobyname(HPHP::String const&)
_ZN4HPHP16f_getprotobynameERKNS_6StringE

(return value) => rax
_rv => rdi
name => rsi
*/

TypedValue* fh_getprotobyname(TypedValue* _rv, Value* name) asm("_ZN4HPHP16f_getprotobynameERKNS_6StringE");

TypedValue * fg1_getprotobyname(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_getprotobyname(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToStringInPlace(args-0);
  fh_getprotobyname((rv), &args[-0].m_data);
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_getprotobyname(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      if (IS_STRING_TYPE((args-0)->m_type)) {
        fh_getprotobyname((&(rv)), &args[-0].m_data);
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_getprotobyname(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("getprotobyname", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_getprotobynumber(int)
_ZN4HPHP18f_getprotobynumberEi

(return value) => rax
_rv => rdi
number => rsi
*/

TypedValue* fh_getprotobynumber(TypedValue* _rv, int number) asm("_ZN4HPHP18f_getprotobynumberEi");

TypedValue * fg1_getprotobynumber(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_getprotobynumber(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToInt64InPlace(args-0);
  fh_getprotobynumber((rv), (int)(args[-0].m_data.num));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_getprotobynumber(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      if ((args-0)->m_type == KindOfInt64) {
        fh_getprotobynumber((&(rv)), (int)(args[-0].m_data.num));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_getprotobynumber(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("getprotobynumber", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_getservbyname(HPHP::String const&, HPHP::String const&)
_ZN4HPHP15f_getservbynameERKNS_6StringES2_

(return value) => rax
_rv => rdi
service => rsi
protocol => rdx
*/

TypedValue* fh_getservbyname(TypedValue* _rv, Value* service, Value* protocol) asm("_ZN4HPHP15f_getservbynameERKNS_6StringES2_");

TypedValue * fg1_getservbyname(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_getservbyname(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  if (!IS_STRING_TYPE((args-1)->m_type)) {
    tvCastToStringInPlace(args-1);
  }
  if (!IS_STRING_TYPE((args-0)->m_type)) {
    tvCastToStringInPlace(args-0);
  }
  fh_getservbyname((rv), &args[-0].m_data, &args[-1].m_data);
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_getservbyname(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 2LL) {
      if (IS_STRING_TYPE((args-1)->m_type) && IS_STRING_TYPE((args-0)->m_type)) {
        fh_getservbyname((&(rv)), &args[-0].m_data, &args[-1].m_data);
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_getservbyname(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("getservbyname", count, 2, 2, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_getservbyport(int, HPHP::String const&)
_ZN4HPHP15f_getservbyportEiRKNS_6StringE

(return value) => rax
_rv => rdi
port => rsi
protocol => rdx
*/

TypedValue* fh_getservbyport(TypedValue* _rv, int port, Value* protocol) asm("_ZN4HPHP15f_getservbyportEiRKNS_6StringE");

TypedValue * fg1_getservbyport(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_getservbyport(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  if (!IS_STRING_TYPE((args-1)->m_type)) {
    tvCastToStringInPlace(args-1);
  }
  if ((args-0)->m_type != KindOfInt64) {
    tvCastToInt64InPlace(args-0);
  }
  fh_getservbyport((rv), (int)(args[-0].m_data.num), &args[-1].m_data);
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_getservbyport(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 2LL) {
      if (IS_STRING_TYPE((args-1)->m_type) && (args-0)->m_type == KindOfInt64) {
        fh_getservbyport((&(rv)), (int)(args[-0].m_data.num), &args[-1].m_data);
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_getservbyport(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("getservbyport", count, 2, 2, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_inet_ntop(HPHP::String const&)
_ZN4HPHP11f_inet_ntopERKNS_6StringE

(return value) => rax
_rv => rdi
in_addr => rsi
*/

TypedValue* fh_inet_ntop(TypedValue* _rv, Value* in_addr) asm("_ZN4HPHP11f_inet_ntopERKNS_6StringE");

TypedValue * fg1_inet_ntop(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_inet_ntop(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToStringInPlace(args-0);
  fh_inet_ntop((rv), &args[-0].m_data);
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_inet_ntop(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      if (IS_STRING_TYPE((args-0)->m_type)) {
        fh_inet_ntop((&(rv)), &args[-0].m_data);
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_inet_ntop(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("inet_ntop", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_inet_pton(HPHP::String const&)
_ZN4HPHP11f_inet_ptonERKNS_6StringE

(return value) => rax
_rv => rdi
address => rsi
*/

TypedValue* fh_inet_pton(TypedValue* _rv, Value* address) asm("_ZN4HPHP11f_inet_ptonERKNS_6StringE");

TypedValue * fg1_inet_pton(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_inet_pton(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToStringInPlace(args-0);
  fh_inet_pton((rv), &args[-0].m_data);
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_inet_pton(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      if (IS_STRING_TYPE((args-0)->m_type)) {
        fh_inet_pton((&(rv)), &args[-0].m_data);
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_inet_pton(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("inet_pton", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_ip2long(HPHP::String const&)
_ZN4HPHP9f_ip2longERKNS_6StringE

(return value) => rax
_rv => rdi
ip_address => rsi
*/

TypedValue* fh_ip2long(TypedValue* _rv, Value* ip_address) asm("_ZN4HPHP9f_ip2longERKNS_6StringE");

TypedValue * fg1_ip2long(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_ip2long(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToStringInPlace(args-0);
  fh_ip2long((rv), &args[-0].m_data);
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_ip2long(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      if (IS_STRING_TYPE((args-0)->m_type)) {
        fh_ip2long((&(rv)), &args[-0].m_data);
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_ip2long(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("ip2long", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::String HPHP::f_long2ip(int)
_ZN4HPHP9f_long2ipEi

(return value) => rax
_rv => rdi
proper_address => rsi
*/

Value* fh_long2ip(Value* _rv, int proper_address) asm("_ZN4HPHP9f_long2ipEi");

TypedValue * fg1_long2ip(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_long2ip(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfString;
  tvCastToInt64InPlace(args-0);
  fh_long2ip((&rv->m_data), (int)(args[-0].m_data.num));
  if (rv->m_data.num == 0LL) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_long2ip(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      if ((args-0)->m_type == KindOfInt64) {
        rv.m_type = KindOfString;
        fh_long2ip((&rv.m_data), (int)(args[-0].m_data.num));
        if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_long2ip(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("long2ip", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_dns_check_record(HPHP::String const&, HPHP::String const&)
_ZN4HPHP18f_dns_check_recordERKNS_6StringES2_

(return value) => rax
host => rdi
type => rsi
*/

bool fh_dns_check_record(Value* host, Value* type) asm("_ZN4HPHP18f_dns_check_recordERKNS_6StringES2_");

TypedValue * fg1_dns_check_record(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_dns_check_record(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfBoolean;
  switch (count) {
  default: // count >= 2
    if (!IS_STRING_TYPE((args-1)->m_type)) {
      tvCastToStringInPlace(args-1);
    }
  case 1:
    break;
  }
  if (!IS_STRING_TYPE((args-0)->m_type)) {
    tvCastToStringInPlace(args-0);
  }
  rv->m_data.num = (fh_dns_check_record(&args[-0].m_data, (count > 1) ? &args[-1].m_data : (Value*)(&null_string))) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_dns_check_record(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count >= 1LL && count <= 2LL) {
      if ((count <= 1 || IS_STRING_TYPE((args-1)->m_type)) && IS_STRING_TYPE((args-0)->m_type)) {
        rv.m_type = KindOfBoolean;
        rv.m_data.num = (fh_dns_check_record(&args[-0].m_data, (count > 1) ? &args[-1].m_data : (Value*)(&null_string))) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_dns_check_record(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("dns_check_record", count, 1, 2, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_checkdnsrr(HPHP::String const&, HPHP::String const&)
_ZN4HPHP12f_checkdnsrrERKNS_6StringES2_

(return value) => rax
host => rdi
type => rsi
*/

bool fh_checkdnsrr(Value* host, Value* type) asm("_ZN4HPHP12f_checkdnsrrERKNS_6StringES2_");

TypedValue * fg1_checkdnsrr(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_checkdnsrr(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfBoolean;
  switch (count) {
  default: // count >= 2
    if (!IS_STRING_TYPE((args-1)->m_type)) {
      tvCastToStringInPlace(args-1);
    }
  case 1:
    break;
  }
  if (!IS_STRING_TYPE((args-0)->m_type)) {
    tvCastToStringInPlace(args-0);
  }
  rv->m_data.num = (fh_checkdnsrr(&args[-0].m_data, (count > 1) ? &args[-1].m_data : (Value*)(&null_string))) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_checkdnsrr(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count >= 1LL && count <= 2LL) {
      if ((count <= 1 || IS_STRING_TYPE((args-1)->m_type)) && IS_STRING_TYPE((args-0)->m_type)) {
        rv.m_type = KindOfBoolean;
        rv.m_data.num = (fh_checkdnsrr(&args[-0].m_data, (count > 1) ? &args[-1].m_data : (Value*)(&null_string))) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_checkdnsrr(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("checkdnsrr", count, 1, 2, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_dns_get_record(HPHP::String const&, int, HPHP::VRefParamValue const&, HPHP::VRefParamValue const&)
_ZN4HPHP16f_dns_get_recordERKNS_6StringEiRKNS_14VRefParamValueES5_

(return value) => rax
_rv => rdi
hostname => rsi
type => rdx
authns => rcx
addtl => r8
*/

TypedValue* fh_dns_get_record(TypedValue* _rv, Value* hostname, int type, TypedValue* authns, TypedValue* addtl) asm("_ZN4HPHP16f_dns_get_recordERKNS_6StringEiRKNS_14VRefParamValueES5_");

TypedValue * fg1_dns_get_record(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_dns_get_record(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  switch (count) {
  default: // count >= 4
  case 3:
  case 2:
    if ((args-1)->m_type != KindOfInt64) {
      tvCastToInt64InPlace(args-1);
    }
  case 1:
    break;
  }
  if (!IS_STRING_TYPE((args-0)->m_type)) {
    tvCastToStringInPlace(args-0);
  }
  VRefParamValue defVal2 = uninit_null();
  VRefParamValue defVal3 = uninit_null();
  fh_dns_get_record((rv), &args[-0].m_data, (count > 1) ? (int)(args[-1].m_data.num) : (int)(-1), (count > 2) ? (args-2) : (TypedValue*)(&defVal2), (count > 3) ? (args-3) : (TypedValue*)(&defVal3));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_dns_get_record(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count >= 1LL && count <= 4LL) {
      if ((count <= 1 || (args-1)->m_type == KindOfInt64) && IS_STRING_TYPE((args-0)->m_type)) {
        VRefParamValue defVal2 = uninit_null();
        VRefParamValue defVal3 = uninit_null();
        fh_dns_get_record((&(rv)), &args[-0].m_data, (count > 1) ? (int)(args[-1].m_data.num) : (int)(-1), (count > 2) ? (args-2) : (TypedValue*)(&defVal2), (count > 3) ? (args-3) : (TypedValue*)(&defVal3));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 4);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_dns_get_record(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 4);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("dns_get_record", count, 1, 4, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 4);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_dns_get_mx(HPHP::String const&, HPHP::VRefParamValue const&, HPHP::VRefParamValue const&)
_ZN4HPHP12f_dns_get_mxERKNS_6StringERKNS_14VRefParamValueES5_

(return value) => rax
hostname => rdi
mxhosts => rsi
weights => rdx
*/

bool fh_dns_get_mx(Value* hostname, TypedValue* mxhosts, TypedValue* weights) asm("_ZN4HPHP12f_dns_get_mxERKNS_6StringERKNS_14VRefParamValueES5_");

TypedValue * fg1_dns_get_mx(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_dns_get_mx(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfBoolean;
  tvCastToStringInPlace(args-0);
  VRefParamValue defVal2 = uninit_null();
  rv->m_data.num = (fh_dns_get_mx(&args[-0].m_data, (args-1), (count > 2) ? (args-2) : (TypedValue*)(&defVal2))) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_dns_get_mx(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count >= 2LL && count <= 3LL) {
      if (IS_STRING_TYPE((args-0)->m_type)) {
        rv.m_type = KindOfBoolean;
        VRefParamValue defVal2 = uninit_null();
        rv.m_data.num = (fh_dns_get_mx(&args[-0].m_data, (args-1), (count > 2) ? (args-2) : (TypedValue*)(&defVal2))) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_dns_get_mx(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("dns_get_mx", count, 2, 3, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 3);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_getmxrr(HPHP::String const&, HPHP::VRefParamValue const&, HPHP::VRefParamValue const&)
_ZN4HPHP9f_getmxrrERKNS_6StringERKNS_14VRefParamValueES5_

(return value) => rax
hostname => rdi
mxhosts => rsi
weight => rdx
*/

bool fh_getmxrr(Value* hostname, TypedValue* mxhosts, TypedValue* weight) asm("_ZN4HPHP9f_getmxrrERKNS_6StringERKNS_14VRefParamValueES5_");

TypedValue * fg1_getmxrr(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_getmxrr(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfBoolean;
  tvCastToStringInPlace(args-0);
  VRefParamValue defVal2 = uninit_null();
  rv->m_data.num = (fh_getmxrr(&args[-0].m_data, (args-1), (count > 2) ? (args-2) : (TypedValue*)(&defVal2))) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_getmxrr(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count >= 2LL && count <= 3LL) {
      if (IS_STRING_TYPE((args-0)->m_type)) {
        rv.m_type = KindOfBoolean;
        VRefParamValue defVal2 = uninit_null();
        rv.m_data.num = (fh_getmxrr(&args[-0].m_data, (args-1), (count > 2) ? (args-2) : (TypedValue*)(&defVal2))) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_getmxrr(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("getmxrr", count, 2, 3, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 3);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_socket_get_status(HPHP::Object const&)
_ZN4HPHP19f_socket_get_statusERKNS_6ObjectE

(return value) => rax
_rv => rdi
stream => rsi
*/

TypedValue* fh_socket_get_status(TypedValue* _rv, Value* stream) asm("_ZN4HPHP19f_socket_get_statusERKNS_6ObjectE");

TypedValue * fg1_socket_get_status(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_socket_get_status(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToObjectInPlace(args-0);
  fh_socket_get_status((rv), &args[-0].m_data);
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_socket_get_status(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      if ((args-0)->m_type == KindOfObject) {
        fh_socket_get_status((&(rv)), &args[-0].m_data);
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_socket_get_status(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("socket_get_status", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_socket_set_blocking(HPHP::Object const&, int)
_ZN4HPHP21f_socket_set_blockingERKNS_6ObjectEi

(return value) => rax
stream => rdi
mode => rsi
*/

bool fh_socket_set_blocking(Value* stream, int mode) asm("_ZN4HPHP21f_socket_set_blockingERKNS_6ObjectEi");

TypedValue * fg1_socket_set_blocking(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_socket_set_blocking(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfBoolean;
  if ((args-1)->m_type != KindOfInt64) {
    tvCastToInt64InPlace(args-1);
  }
  if ((args-0)->m_type != KindOfObject) {
    tvCastToObjectInPlace(args-0);
  }
  rv->m_data.num = (fh_socket_set_blocking(&args[-0].m_data, (int)(args[-1].m_data.num))) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_socket_set_blocking(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 2LL) {
      if ((args-1)->m_type == KindOfInt64 && (args-0)->m_type == KindOfObject) {
        rv.m_type = KindOfBoolean;
        rv.m_data.num = (fh_socket_set_blocking(&args[-0].m_data, (int)(args[-1].m_data.num))) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_socket_set_blocking(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("socket_set_blocking", count, 2, 2, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_socket_set_timeout(HPHP::Object const&, int, int)
_ZN4HPHP20f_socket_set_timeoutERKNS_6ObjectEii

(return value) => rax
stream => rdi
seconds => rsi
microseconds => rdx
*/

bool fh_socket_set_timeout(Value* stream, int seconds, int microseconds) asm("_ZN4HPHP20f_socket_set_timeoutERKNS_6ObjectEii");

TypedValue * fg1_socket_set_timeout(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_socket_set_timeout(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfBoolean;
  switch (count) {
  default: // count >= 3
    if ((args-2)->m_type != KindOfInt64) {
      tvCastToInt64InPlace(args-2);
    }
  case 2:
    break;
  }
  if ((args-1)->m_type != KindOfInt64) {
    tvCastToInt64InPlace(args-1);
  }
  if ((args-0)->m_type != KindOfObject) {
    tvCastToObjectInPlace(args-0);
  }
  rv->m_data.num = (fh_socket_set_timeout(&args[-0].m_data, (int)(args[-1].m_data.num), (count > 2) ? (int)(args[-2].m_data.num) : (int)(0))) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_socket_set_timeout(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count >= 2LL && count <= 3LL) {
      if ((count <= 2 || (args-2)->m_type == KindOfInt64) && (args-1)->m_type == KindOfInt64 && (args-0)->m_type == KindOfObject) {
        rv.m_type = KindOfBoolean;
        rv.m_data.num = (fh_socket_set_timeout(&args[-0].m_data, (int)(args[-1].m_data.num), (count > 2) ? (int)(args[-2].m_data.num) : (int)(0))) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_socket_set_timeout(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("socket_set_timeout", count, 2, 3, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 3);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
void HPHP::f_header(HPHP::String const&, bool, int)
_ZN4HPHP8f_headerERKNS_6StringEbi

str => rdi
replace => rsi
http_response_code => rdx
*/

void fh_header(Value* str, bool replace, int http_response_code) asm("_ZN4HPHP8f_headerERKNS_6StringEbi");

TypedValue * fg1_header(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_header(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_data.num = 0LL;
  rv->m_type = KindOfNull;
  switch (count) {
  default: // count >= 3
    if ((args-2)->m_type != KindOfInt64) {
      tvCastToInt64InPlace(args-2);
    }
  case 2:
    if ((args-1)->m_type != KindOfBoolean) {
      tvCastToBooleanInPlace(args-1);
    }
  case 1:
    break;
  }
  if (!IS_STRING_TYPE((args-0)->m_type)) {
    tvCastToStringInPlace(args-0);
  }
  fh_header(&args[-0].m_data, (count > 1) ? (bool)(args[-1].m_data.num) : (bool)(true), (count > 2) ? (int)(args[-2].m_data.num) : (int)(0));
  return rv;
}

TypedValue* fg_header(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count >= 1LL && count <= 3LL) {
      if ((count <= 2 || (args-2)->m_type == KindOfInt64) && (count <= 1 || (args-1)->m_type == KindOfBoolean) && IS_STRING_TYPE((args-0)->m_type)) {
        rv.m_data.num = 0LL;
        rv.m_type = KindOfNull;
        fh_header(&args[-0].m_data, (count > 1) ? (bool)(args[-1].m_data.num) : (bool)(true), (count > 2) ? (int)(args[-2].m_data.num) : (int)(0));
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_header(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("header", count, 1, 3, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 3);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Variant HPHP::f_http_response_code(int)
_ZN4HPHP20f_http_response_codeEi

(return value) => rax
_rv => rdi
response_code => rsi
*/

TypedValue* fh_http_response_code(TypedValue* _rv, int response_code) asm("_ZN4HPHP20f_http_response_codeEi");

TypedValue * fg1_http_response_code(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_http_response_code(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  tvCastToInt64InPlace(args-0);
  fh_http_response_code((rv), (count > 0) ? (int)(args[-0].m_data.num) : (int)(0));
  if (rv->m_type == KindOfUninit) rv->m_type = KindOfNull;
  return rv;
}

TypedValue* fg_http_response_code(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 1LL) {
      if ((count <= 0 || (args-0)->m_type == KindOfInt64)) {
        fh_http_response_code((&(rv)), (count > 0) ? (int)(args[-0].m_data.num) : (int)(0));
        if (rv.m_type == KindOfUninit) rv.m_type = KindOfNull;
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_http_response_code(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("http_response_code", 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
HPHP::Array HPHP::f_headers_list()
_ZN4HPHP14f_headers_listEv

(return value) => rax
_rv => rdi
*/

Value* fh_headers_list(Value* _rv) asm("_ZN4HPHP14f_headers_listEv");

TypedValue* fg_headers_list(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 0LL) {
      rv.m_type = KindOfArray;
      fh_headers_list((&rv.m_data));
      if (rv.m_data.num == 0LL) rv.m_type = KindOfNull;
      frame_free_locals_no_this_inl(ar, 0);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("headers_list", 0, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
int HPHP::f_get_http_request_size()
_ZN4HPHP23f_get_http_request_sizeEv

(return value) => rax
*/

int fh_get_http_request_size() asm("_ZN4HPHP23f_get_http_request_sizeEv");

TypedValue* fg_get_http_request_size(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 0LL) {
      rv.m_type = KindOfInt64;
      rv.m_data.num = (int64_t)fh_get_http_request_size();
      frame_free_locals_no_this_inl(ar, 0);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("get_http_request_size", 0, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_headers_sent(HPHP::VRefParamValue const&, HPHP::VRefParamValue const&)
_ZN4HPHP14f_headers_sentERKNS_14VRefParamValueES2_

(return value) => rax
file => rdi
line => rsi
*/

bool fh_headers_sent(TypedValue* file, TypedValue* line) asm("_ZN4HPHP14f_headers_sentERKNS_14VRefParamValueES2_");

TypedValue* fg_headers_sent(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 2LL) {
      rv.m_type = KindOfBoolean;
      VRefParamValue defVal0 = uninit_null();
      VRefParamValue defVal1 = uninit_null();
      rv.m_data.num = (fh_headers_sent((count > 0) ? (args-0) : (TypedValue*)(&defVal0), (count > 1) ? (args-1) : (TypedValue*)(&defVal1))) ? 1LL : 0LL;
      frame_free_locals_no_this_inl(ar, 2);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("headers_sent", 2, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_header_register_callback(HPHP::Variant const&)
_ZN4HPHP26f_header_register_callbackERKNS_7VariantE

(return value) => rax
callback => rdi
*/

bool fh_header_register_callback(TypedValue* callback) asm("_ZN4HPHP26f_header_register_callbackERKNS_7VariantE");

TypedValue* fg_header_register_callback(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 1LL) {
      rv.m_type = KindOfBoolean;
      rv.m_data.num = (fh_header_register_callback((args-0))) ? 1LL : 0LL;
      frame_free_locals_no_this_inl(ar, 1);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_wrong_arguments_nr("header_register_callback", count, 1, 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
void HPHP::f_header_remove(HPHP::String const&)
_ZN4HPHP15f_header_removeERKNS_6StringE

name => rdi
*/

void fh_header_remove(Value* name) asm("_ZN4HPHP15f_header_removeERKNS_6StringE");

TypedValue * fg1_header_remove(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_header_remove(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_data.num = 0LL;
  rv->m_type = KindOfNull;
  tvCastToStringInPlace(args-0);
  fh_header_remove((count > 0) ? &args[-0].m_data : (Value*)(&null_string));
  return rv;
}

TypedValue* fg_header_remove(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count <= 1LL) {
      if ((count <= 0 || IS_STRING_TYPE((args-0)->m_type))) {
        rv.m_data.num = 0LL;
        rv.m_type = KindOfNull;
        fh_header_remove((count > 0) ? &args[-0].m_data : (Value*)(&null_string));
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_header_remove(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 1);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_toomany_arguments_nr("header_remove", 1, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 1);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_setcookie(HPHP::String const&, HPHP::String const&, long, HPHP::String const&, HPHP::String const&, bool, bool)
_ZN4HPHP11f_setcookieERKNS_6StringES2_lS2_S2_bb

(return value) => rax
name => rdi
value => rsi
expire => rdx
path => rcx
domain => r8
secure => r9
httponly => st0
*/

bool fh_setcookie(Value* name, Value* value, long expire, Value* path, Value* domain, bool secure, bool httponly) asm("_ZN4HPHP11f_setcookieERKNS_6StringES2_lS2_S2_bb");

TypedValue * fg1_setcookie(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_setcookie(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfBoolean;
  switch (count) {
  default: // count >= 7
    if ((args-6)->m_type != KindOfBoolean) {
      tvCastToBooleanInPlace(args-6);
    }
  case 6:
    if ((args-5)->m_type != KindOfBoolean) {
      tvCastToBooleanInPlace(args-5);
    }
  case 5:
    if (!IS_STRING_TYPE((args-4)->m_type)) {
      tvCastToStringInPlace(args-4);
    }
  case 4:
    if (!IS_STRING_TYPE((args-3)->m_type)) {
      tvCastToStringInPlace(args-3);
    }
  case 3:
    if ((args-2)->m_type != KindOfInt64) {
      tvCastToInt64InPlace(args-2);
    }
  case 2:
    if (!IS_STRING_TYPE((args-1)->m_type)) {
      tvCastToStringInPlace(args-1);
    }
  case 1:
    break;
  }
  if (!IS_STRING_TYPE((args-0)->m_type)) {
    tvCastToStringInPlace(args-0);
  }
  rv->m_data.num = (fh_setcookie(&args[-0].m_data, (count > 1) ? &args[-1].m_data : (Value*)(&null_string), (count > 2) ? (long)(args[-2].m_data.num) : (long)(0), (count > 3) ? &args[-3].m_data : (Value*)(&null_string), (count > 4) ? &args[-4].m_data : (Value*)(&null_string), (count > 5) ? (bool)(args[-5].m_data.num) : (bool)(false), (count > 6) ? (bool)(args[-6].m_data.num) : (bool)(false))) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_setcookie(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count >= 1LL && count <= 7LL) {
      if ((count <= 6 || (args-6)->m_type == KindOfBoolean) && (count <= 5 || (args-5)->m_type == KindOfBoolean) && (count <= 4 || IS_STRING_TYPE((args-4)->m_type)) && (count <= 3 || IS_STRING_TYPE((args-3)->m_type)) && (count <= 2 || (args-2)->m_type == KindOfInt64) && (count <= 1 || IS_STRING_TYPE((args-1)->m_type)) && IS_STRING_TYPE((args-0)->m_type)) {
        rv.m_type = KindOfBoolean;
        rv.m_data.num = (fh_setcookie(&args[-0].m_data, (count > 1) ? &args[-1].m_data : (Value*)(&null_string), (count > 2) ? (long)(args[-2].m_data.num) : (long)(0), (count > 3) ? &args[-3].m_data : (Value*)(&null_string), (count > 4) ? &args[-4].m_data : (Value*)(&null_string), (count > 5) ? (bool)(args[-5].m_data.num) : (bool)(false), (count > 6) ? (bool)(args[-6].m_data.num) : (bool)(false))) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 7);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_setcookie(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 7);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("setcookie", count, 1, 7, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 7);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_setrawcookie(HPHP::String const&, HPHP::String const&, long, HPHP::String const&, HPHP::String const&, bool, bool)
_ZN4HPHP14f_setrawcookieERKNS_6StringES2_lS2_S2_bb

(return value) => rax
name => rdi
value => rsi
expire => rdx
path => rcx
domain => r8
secure => r9
httponly => st0
*/

bool fh_setrawcookie(Value* name, Value* value, long expire, Value* path, Value* domain, bool secure, bool httponly) asm("_ZN4HPHP14f_setrawcookieERKNS_6StringES2_lS2_S2_bb");

TypedValue * fg1_setrawcookie(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_setrawcookie(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfBoolean;
  switch (count) {
  default: // count >= 7
    if ((args-6)->m_type != KindOfBoolean) {
      tvCastToBooleanInPlace(args-6);
    }
  case 6:
    if ((args-5)->m_type != KindOfBoolean) {
      tvCastToBooleanInPlace(args-5);
    }
  case 5:
    if (!IS_STRING_TYPE((args-4)->m_type)) {
      tvCastToStringInPlace(args-4);
    }
  case 4:
    if (!IS_STRING_TYPE((args-3)->m_type)) {
      tvCastToStringInPlace(args-3);
    }
  case 3:
    if ((args-2)->m_type != KindOfInt64) {
      tvCastToInt64InPlace(args-2);
    }
  case 2:
    if (!IS_STRING_TYPE((args-1)->m_type)) {
      tvCastToStringInPlace(args-1);
    }
  case 1:
    break;
  }
  if (!IS_STRING_TYPE((args-0)->m_type)) {
    tvCastToStringInPlace(args-0);
  }
  rv->m_data.num = (fh_setrawcookie(&args[-0].m_data, (count > 1) ? &args[-1].m_data : (Value*)(&null_string), (count > 2) ? (long)(args[-2].m_data.num) : (long)(0), (count > 3) ? &args[-3].m_data : (Value*)(&null_string), (count > 4) ? &args[-4].m_data : (Value*)(&null_string), (count > 5) ? (bool)(args[-5].m_data.num) : (bool)(false), (count > 6) ? (bool)(args[-6].m_data.num) : (bool)(false))) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_setrawcookie(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count >= 1LL && count <= 7LL) {
      if ((count <= 6 || (args-6)->m_type == KindOfBoolean) && (count <= 5 || (args-5)->m_type == KindOfBoolean) && (count <= 4 || IS_STRING_TYPE((args-4)->m_type)) && (count <= 3 || IS_STRING_TYPE((args-3)->m_type)) && (count <= 2 || (args-2)->m_type == KindOfInt64) && (count <= 1 || IS_STRING_TYPE((args-1)->m_type)) && IS_STRING_TYPE((args-0)->m_type)) {
        rv.m_type = KindOfBoolean;
        rv.m_data.num = (fh_setrawcookie(&args[-0].m_data, (count > 1) ? &args[-1].m_data : (Value*)(&null_string), (count > 2) ? (long)(args[-2].m_data.num) : (long)(0), (count > 3) ? &args[-3].m_data : (Value*)(&null_string), (count > 4) ? &args[-4].m_data : (Value*)(&null_string), (count > 5) ? (bool)(args[-5].m_data.num) : (bool)(false), (count > 6) ? (bool)(args[-6].m_data.num) : (bool)(false))) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 7);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_setrawcookie(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 7);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("setrawcookie", count, 1, 7, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 7);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
void HPHP::f_define_syslog_variables()
_ZN4HPHP25f_define_syslog_variablesEv

*/

void fh_define_syslog_variables() asm("_ZN4HPHP25f_define_syslog_variablesEv");

TypedValue* fg_define_syslog_variables(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 0LL) {
      rv.m_data.num = 0LL;
      rv.m_type = KindOfNull;
      fh_define_syslog_variables();
      frame_free_locals_no_this_inl(ar, 0);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("define_syslog_variables", 0, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_openlog(HPHP::String const&, int, int)
_ZN4HPHP9f_openlogERKNS_6StringEii

(return value) => rax
ident => rdi
option => rsi
facility => rdx
*/

bool fh_openlog(Value* ident, int option, int facility) asm("_ZN4HPHP9f_openlogERKNS_6StringEii");

TypedValue * fg1_openlog(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_openlog(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfBoolean;
  if ((args-2)->m_type != KindOfInt64) {
    tvCastToInt64InPlace(args-2);
  }
  if ((args-1)->m_type != KindOfInt64) {
    tvCastToInt64InPlace(args-1);
  }
  if (!IS_STRING_TYPE((args-0)->m_type)) {
    tvCastToStringInPlace(args-0);
  }
  rv->m_data.num = (fh_openlog(&args[-0].m_data, (int)(args[-1].m_data.num), (int)(args[-2].m_data.num))) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_openlog(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 3LL) {
      if ((args-2)->m_type == KindOfInt64 && (args-1)->m_type == KindOfInt64 && IS_STRING_TYPE((args-0)->m_type)) {
        rv.m_type = KindOfBoolean;
        rv.m_data.num = (fh_openlog(&args[-0].m_data, (int)(args[-1].m_data.num), (int)(args[-2].m_data.num))) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_openlog(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 3);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("openlog", count, 3, 3, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 3);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_closelog()
_ZN4HPHP10f_closelogEv

(return value) => rax
*/

bool fh_closelog() asm("_ZN4HPHP10f_closelogEv");

TypedValue* fg_closelog(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 0LL) {
      rv.m_type = KindOfBoolean;
      rv.m_data.num = (fh_closelog()) ? 1LL : 0LL;
      frame_free_locals_no_this_inl(ar, 0);
      memcpy(&ar->m_r, &rv, sizeof(TypedValue));
      return &ar->m_r;
    } else {
      throw_toomany_arguments_nr("closelog", 0, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 0);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}



/*
bool HPHP::f_syslog(int, HPHP::String const&)
_ZN4HPHP8f_syslogEiRKNS_6StringE

(return value) => rax
priority => rdi
message => rsi
*/

bool fh_syslog(int priority, Value* message) asm("_ZN4HPHP8f_syslogEiRKNS_6StringE");

TypedValue * fg1_syslog(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) __attribute__((noinline,cold));
TypedValue * fg1_syslog(TypedValue* rv, HPHP::VM::ActRec* ar, int64_t count) {
  TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
  rv->m_type = KindOfBoolean;
  if (!IS_STRING_TYPE((args-1)->m_type)) {
    tvCastToStringInPlace(args-1);
  }
  if ((args-0)->m_type != KindOfInt64) {
    tvCastToInt64InPlace(args-0);
  }
  rv->m_data.num = (fh_syslog((int)(args[-0].m_data.num), &args[-1].m_data)) ? 1LL : 0LL;
  return rv;
}

TypedValue* fg_syslog(HPHP::VM::ActRec *ar) {
    TypedValue rv;
    int64_t count = ar->numArgs();
    TypedValue* args UNUSED = ((TypedValue*)ar) - 1;
    if (count == 2LL) {
      if (IS_STRING_TYPE((args-1)->m_type) && (args-0)->m_type == KindOfInt64) {
        rv.m_type = KindOfBoolean;
        rv.m_data.num = (fh_syslog((int)(args[-0].m_data.num), &args[-1].m_data)) ? 1LL : 0LL;
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      } else {
        fg1_syslog(&rv, ar, count);
        frame_free_locals_no_this_inl(ar, 2);
        memcpy(&ar->m_r, &rv, sizeof(TypedValue));
        return &ar->m_r;
      }
    } else {
      throw_wrong_arguments_nr("syslog", count, 2, 2, 1);
    }
    rv.m_data.num = 0LL;
    rv.m_type = KindOfNull;
    frame_free_locals_no_this_inl(ar, 2);
    memcpy(&ar->m_r, &rv, sizeof(TypedValue));
    return &ar->m_r;
  return &ar->m_r;
}




} // !HPHP

