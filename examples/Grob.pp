@disregard
// The MIT License (MIT)
//
// Copyright (c) 2023-2025 Insoft. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
@end

#pragma mode( separator(.,;) integer(h64) )

#define Bitmap bitWidth[1], width[2], height[3], colorsUsed[4], palette[5]
#define dict(d, v) def dictionary: $1 $2

def BITSR   bit::sr;
func(auto:bitmap)
begin
    def dictionary: Bitmap bitmap;

    auto i, j;
    auto palette, data, length;

    data = bitmap[5 + bitmap.colorsUsed];
    length = bitmap.width * bitmap.height / (64 / bitmap.bitWidth);

    for i = 0 ... length - 1 do
        for j = 0 ... 64 / bitmap.bitWidth - 1 do
            bitmap.palette[1];
data + 1 => data;
if i == 7 and k < L then
endif;
bit::sr(i, 8);

        end;
    end;
end;
