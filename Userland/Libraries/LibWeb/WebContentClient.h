/*
 * Copyright (c) 2020-2021, Andreas Kling <kling@serenityos.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <AK/HashMap.h>
#include <LibIPC/ServerConnection.h>
#include <WebContent/WebContentClientEndpoint.h>
#include <WebContent/WebContentServerEndpoint.h>

namespace Web {

class OutOfProcessWebView;

class WebContentClient final
    : public IPC::ServerConnection<WebContentClientEndpoint, WebContentServerEndpoint>
    , public WebContentClientEndpoint {
    C_OBJECT(WebContentClient);

public:
    virtual void handshake() override;

    Function<void()> on_web_content_process_crash;

private:
    WebContentClient(OutOfProcessWebView&);

    virtual void die() override;

    virtual void handle(const Messages::WebContentClient::DidPaint&) override;
    virtual void handle(const Messages::WebContentClient::DidFinishLoading&) override;
    virtual void handle(const Messages::WebContentClient::DidInvalidateContentRect&) override;
    virtual void handle(const Messages::WebContentClient::DidChangeSelection&) override;
    virtual void handle(const Messages::WebContentClient::DidRequestCursorChange&) override;
    virtual void handle(const Messages::WebContentClient::DidLayout&) override;
    virtual void handle(const Messages::WebContentClient::DidChangeTitle&) override;
    virtual void handle(const Messages::WebContentClient::DidRequestScroll&) override;
    virtual void handle(const Messages::WebContentClient::DidRequestScrollIntoView&) override;
    virtual void handle(const Messages::WebContentClient::DidEnterTooltipArea&) override;
    virtual void handle(const Messages::WebContentClient::DidLeaveTooltipArea&) override;
    virtual void handle(const Messages::WebContentClient::DidHoverLink&) override;
    virtual void handle(const Messages::WebContentClient::DidUnhoverLink&) override;
    virtual void handle(const Messages::WebContentClient::DidClickLink&) override;
    virtual void handle(const Messages::WebContentClient::DidMiddleClickLink&) override;
    virtual void handle(const Messages::WebContentClient::DidStartLoading&) override;
    virtual void handle(const Messages::WebContentClient::DidRequestContextMenu&) override;
    virtual void handle(const Messages::WebContentClient::DidRequestLinkContextMenu&) override;
    virtual void handle(const Messages::WebContentClient::DidRequestImageContextMenu&) override;
    virtual void handle(const Messages::WebContentClient::DidGetSource&) override;
    virtual void handle(const Messages::WebContentClient::DidJSConsoleOutput&) override;
    virtual void handle(const Messages::WebContentClient::DidChangeFavicon&) override;
    virtual OwnPtr<Messages::WebContentClient::DidRequestAlertResponse> handle(const Messages::WebContentClient::DidRequestAlert&) override;
    virtual OwnPtr<Messages::WebContentClient::DidRequestConfirmResponse> handle(const Messages::WebContentClient::DidRequestConfirm&) override;
    virtual OwnPtr<Messages::WebContentClient::DidRequestPromptResponse> handle(const Messages::WebContentClient::DidRequestPrompt&) override;
    virtual OwnPtr<Messages::WebContentClient::DidRequestCookieResponse> handle(const Messages::WebContentClient::DidRequestCookie&) override;
    virtual void handle(const Messages::WebContentClient::DidSetCookie&) override;

    OutOfProcessWebView& m_view;
};

}
