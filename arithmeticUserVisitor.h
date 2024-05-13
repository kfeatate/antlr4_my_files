#pragma once
#include "arithmeticBaseVisitor.h"
#include <iostream>
#include <vector>
#include <cmath>

class arithmeticUserVisitor : public arithmeticBaseVisitor {
public:

    std::vector<int> res;

    virtual std::any visitOneLineProg(arithmeticParser::OneLineProgContext* ctx) override {
        std::cout << "OneLineProg" << std::endl;
        int val = std::any_cast<int>(visit(ctx->expr()));
        res.push_back(val);
        return val;
    }

    virtual std::any visitMultLineProg(arithmeticParser::MultLineProgContext* ctx) override {
        std::cout << "MultLineProg" << std::endl;
        std::vector<arithmeticParser::ProgContext*> arr_p = ctx->prog();
        for each (arithmeticParser::ProgContext * p in arr_p) {
            visit(p);
        }
        return &res;
    }

    virtual std::any visitParens(arithmeticParser::ParensContext* ctx) override {
        std::cout << "Parens" << std::endl;
        return visit(ctx->expr());
    }

    virtual std::any visitMulDiv(arithmeticParser::MulDivContext* ctx) override {
        int left = std::any_cast<int>(visit(ctx->expr(0)));
        int right = std::any_cast<int>(visit(ctx->expr(1)));
        if (ctx->op->getType() == arithmeticParser::MUL) return left * right;
        else return left / right;
    }

    virtual std::any visitAddSub(arithmeticParser::AddSubContext* ctx) override {
        int left = std::any_cast<int>(visit(ctx->expr(0)));
        int right = std::any_cast<int>(visit(ctx->expr(1)));
        if (ctx->op->getType() == arithmeticParser::ADD) return left + right;
        else return left - right;
    }

    virtual std::any visitPOW(arithmeticParser::POWContext* ctx) override {
        int left = std::any_cast<int>(visit(ctx->expr(0)));
        int right = std::any_cast<int>(visit(ctx->expr(1)));
        return left pow (right);
    }

    virtual std::any visitInt(arithmeticParser::IntContext* ctx) override {
        return std::stoi(ctx->INT()->getText());
    }
};