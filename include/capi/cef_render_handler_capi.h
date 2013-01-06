// Copyright (c) 2013 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//

#ifndef CEF_INCLUDE_CAPI_CEF_RENDER_HANDLER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_RENDER_HANDLER_CAPI_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "include/capi/cef_base_capi.h"


///
// Implement this structure to handle events when window rendering is disabled.
// The functions of this structure will be called on the UI thread.
///
typedef struct _cef_render_handler_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Called to retrieve the root window rectangle in screen coordinates. Return
  // true (1) if the rectangle was provided. Return false (0) if the screen
  // rectangle is the same as the view rectangle.
  ///
  int (CEF_CALLBACK *get_root_screen_rect)(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, cef_rect_t* rect);

  ///
  // Called to retrieve the view rectangle which is relative to screen
  // coordinates. Return true (1) if the rectangle was provided.
  ///
  int (CEF_CALLBACK *get_view_rect)(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, cef_rect_t* rect);

  ///
  // Called to retrieve the translation from view coordinates to actual screen
  // coordinates. Return true (1) if the screen coordinates were provided.
  ///
  int (CEF_CALLBACK *get_screen_point)(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, int viewX, int viewY, int* screenX,
      int* screenY);

  ///
  // Called when the browser wants to show or hide the popup widget. The popup
  // should be shown if |show| is true (1) and hidden if |show| is false (0).
  // NOTE: Popup widgets are not yet supported.
  ///
  void (CEF_CALLBACK *on_popup_show)(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, int show);

  ///
  // Called when the browser wants to move or resize the popup widget. |rect|
  // contains the new location and size. NOTE: Popup widgets are not yet
  // supported.
  ///
  void (CEF_CALLBACK *on_popup_size)(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, const cef_rect_t* rect);

  ///
  // Called when an element should be painted. |type| indicates whether the
  // element is the view or the popup widget. |buffer| contains the pixel data
  // for the whole image. |dirtyRects| contains the set of rectangles that need
  // to be repainted. On Windows |buffer| will be |width|*|height|*4 bytes in
  // size and represents a BGRA image with an upper-left origin. NOTE: Popup
  // widgets are not yet supported.
  ///
  void (CEF_CALLBACK *on_paint)(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, enum cef_paint_element_type_t type,
      size_t dirtyRectsCount, cef_rect_t const* dirtyRects, const void* buffer,
      int width, int height);

  ///
  // Called when the browser window's cursor has changed.
  ///
  void (CEF_CALLBACK *on_cursor_change)(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, cef_cursor_handle_t cursor);
} cef_render_handler_t;


#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_RENDER_HANDLER_CAPI_H_