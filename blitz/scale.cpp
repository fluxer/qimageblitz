#include "qimageblitz.h"
#include <string.h>
#include <stdlib.h>

/*
 * Copyright (C) 2004, 2005, 2007 Daniel M. Duley <daniel.duley@verizon.net>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* OTHER CREDITS:
 *
 * This is the normal smoothscale method, based on Imlib2's smoothscale.
 *
 * Originally I took the algorithm used in NetPBM and Qt and added MMX/3dnow
 * optimizations. It ran in about 1/2 the time as Qt. Then I ported Imlib's
 * C algorithm and it ran at about the same speed as my MMX optimized one...
 * Finally I ported Imlib's MMX version and it ran in less than half the
 * time as my MMX algorithm, (taking only a quarter of the time Qt did).
 * After further optimization it seems to run at around 1/6th.
 *
 * Changes include formatting, namespaces and other C++'ings, removal of old
 * #ifdef'ed code, and removal of unneeded border calculation code.
 *
 * Imlib2 is (C) Carsten Haitzler and various contributors. The MMX code
 * is by Willem Monsuwe <willem@stack.nl>. All other modifications are
 * (C) Daniel M. Duley.
 */

QImage Blitz::smoothScale(QImage &src, int w, int h,
                          Qt::AspectRatioMode aspectRatio)
{
    return(smoothScale(src, QSize(w, h), aspectRatio));
}

QImage Blitz::smoothScale(QImage &src, const QSize &sz,
                          Qt::AspectRatioMode aspectRatio)
{
    return(src.scaled(sz, aspectRatio, Qt::SmoothTransformation));
}
